#include <iostream>
#include <fstream> 
#include <string> 
#include <vector> 
#include "json.hpp"
#include "priorityqueue.h" 

int main(int argc, char** argv) {
    std::ifstream file(argv[1]);
    nlohmann::json data = nlohmann::json::parse(file); 
    std::size_t max_size = data["metadata"]["maxHeapSize"];
    PriorityQueue queue(max_size);
    for (auto itr = data.begin(); itr != std::prev(data.end()); ++itr) { 
        if (data[itr.key()]["operation"] == "insert") {
            double k = data[itr.key()]["key"];
            queue.insert(k);
        } else if (data[itr.key()]["operation"] == "removeMin") {
            queue.removeMin();
        }
    } 
    nlohmann::json output = queue.JSON();
    output["metadata"]["numOperations"] = data["metadata"]["numOperations"];
    output["metadata"]["maxHeapSize"] = data["metadata"]["maxHeapSize"];
    std::cout << output.dump(2) << std::endl;
}