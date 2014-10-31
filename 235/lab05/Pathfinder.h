/*
 * Pathfinder.h
 *
 *  Created on: Oct 23, 2014
 *      Author: Spencer
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "PathfinderInterface.h"

using namespace std;

class Pathfinder : public PathfinderInterface {
private:
	string maze[5][5][5];
public:
	Pathfinder();
	~Pathfinder();
	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
};

#endif /* PATHFINDER_H_ */
