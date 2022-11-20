#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"
#include "priorityqueue.h"
#include "teamdata.h"

int main(int argc, char **argv)
{
    std::string filename = argv[1];
    TeamData data(filename);
    PriorityQueue origQueue = data.createQueue();
    std::vector<int> selectedPlayers;
    nlohmann::json output;
    int i = 0;
    std::size_t numPlayers = data.numPlayers();
    while (selectedPlayers.size() < numPlayers)
    {
        PriorityQueue queue = origQueue;
        KeyValuePair prev;
        KeyValuePair next;
        KeyValuePair best;
        bool foundPrev = false;
        bool done = false;
        while (!queue.isEmpty() && done == false)
        {
            bool found = false;
            KeyValuePair min = queue.min();
            for (unsigned int i = 0; i < selectedPlayers.size(); i++)
            {
                found = !(min.second.first != selectedPlayers[i] && min.second.second != selectedPlayers[i]);
                if (found)
                {
                    break;
                }
            }
            if (found == false)
            {
                if ((foundPrev == true && min.first >= 50) || (foundPrev == true && queue.size() == 1))
                {
                    next = min;
                    done = true;
                }
                else
                {
                    prev = min;
                    if (foundPrev == false)
                    {
                        foundPrev = true;
                    }
                }
            }
            queue.removeMin();
        }
        best = prev;
        if (fabs(next.first - 50.0) <= fabs(prev.first - 50.0))
        {
            best = next;
        }
        selectedPlayers.push_back(best.second.first);
        selectedPlayers.push_back(best.second.second);
        output["teams"][i] = {best.second.first, best.second.second};
        i++;
    }
    std::cout << output.dump(2) << std::endl;
}