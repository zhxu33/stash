#include <iostream>  
#include <fstream>  
#include <string> 
#include <vector> 
#include "AVL.h"
#include "json.hpp"
using namespace std;

int main(int argc, char** argv) { 
    ifstream file(argv[1]);
    nlohmann::json data = nlohmann::json::parse(file);
    AVLTree tree;
    for (auto itr = data.begin(); itr != std::prev(data.end()); ++itr) { 
        tree.Insert(data[itr.key()]["key"]);
    } 
    cout << tree.JSON();
}