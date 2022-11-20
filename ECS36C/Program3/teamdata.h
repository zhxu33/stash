#ifndef _TEAMDATA_H_
#define _TEAMDATA_H_

#include <string>
#include "priorityqueue.h" 
#include <map>
#include "json.hpp"

class TeamData {
 public:
 	TeamData(std::string filename);
 	int numPlayers() const {return numPlayers_;};
	int teamSize() const {return teamSize_;};
 	double winPercentages(int i, int j) { return winPercentages_[i][j]; }
	PriorityQueue createQueue();

 private:
	// TODO: decide the type of this variable.
	// winPercentages_;

	std::map<int, std::map<int, double>> winPercentages_;
	int numPlayers_;
	int teamSize_;

};  // class TeamData

#endif  // _TEAMDATA_H_