#include "teamdata.h"
#include <string>
#include <vector>
#include "json.hpp"
#include <iostream>
#include "priorityqueue.h" 
#include <fstream>

TeamData::TeamData(std::string filename) {
    std::ifstream file(filename);
    nlohmann::json data = nlohmann::json::parse(file);
    for (std::size_t i = 0; i < data["teamStats"].size(); i++)
    {
        double percentage = data["teamStats"][i]["winPercentage"];
        int p1 = data["teamStats"][i]["playerOne"];
        int p2 = data["teamStats"][i]["playerTwo"];
        winPercentages_[p1][p2] = percentage;
        teamSize_++;
    }
    numPlayers_ = data["metadata"]["numPlayers"];
}

PriorityQueue TeamData::createQueue() {
    PriorityQueue queue(teamSize_);
    std::map<int, std::map<int, double> >::iterator itr;
    std::map<int, double>::iterator ptr;
    for (itr = winPercentages_.begin(); itr != winPercentages_.end(); itr++) {
        for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
            Value v;
            v.first = itr->first;
            v.second = ptr->first;
            KeyValuePair k;
            k.first = ptr->second;
            k.second = v;
            queue.insert(k);
        }
    }
    return queue;
}