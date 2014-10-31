/*
 * test.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: Spencer
 */

#include <iostream>
#include <string>
#include "Pathfinder.h"
#include "Pathfinder.cpp"

using namespace std;

int main() {
	Pathfinder test;
//	test.createRandomMaze();
//	cout << test.getMaze();

	if (test.importMaze("test.txt")) {
		cout << "Maze is valid!" << endl;
	}
	if (!test.importMaze("test.txt")) {
		cout << "Maze is invalid!" << endl;
	}
	return 0;
}