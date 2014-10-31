/*
 * Pathfinder.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: Spencer
 */

#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder() {
	srand (time(NULL));
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				maze[x][y][z] = "1";
			}
		}
	}
}


Pathfinder::~Pathfinder() {}

string Pathfinder::getMaze() {
	string maze_container;
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				maze_container += maze[x][y][z];
				if (x == 4) {
					if (!(y == 4 && z == 4)) {
						maze_container += "\n";
					}
				}
				else maze_container += " ";
			}
		}
		if (z != 4) {
			maze_container += "\n";
		}
	}
	return maze_container;
}

void Pathfinder::createRandomMaze() {
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				int cell = rand() % 2;
				if (cell == 0) {
					maze[x][y][z] = "0";
				}
				else maze[x][y][z] = "1";
			}
		}
	}
	maze[0][0][0] = "1";
	maze[4][4][4] = "1";
}

bool Pathfinder::importMaze(string file_name) {
	fstream file(file_name);
	string str(istreambuf_iterator<char>(file), 
		(istreambuf_iterator<char>()));
	string test;
	string item;
	string temp;
	int count;
	stringstream stream(str);
	while (stream >> item) {
		test = item;
		if (test != "0" && test != "1") {
			return false;
		}
		if (count == 0 && test != "1") {
			return false;
		}
		if (count == 124 && test != "1") {
			return false;
		}
		count++;
		temporary += item + " ";
	}
	if (count != 125) {
		return false;
	}
	stringstream maze(temp)
	return true;
}

vector<string> Pathfinder::solveMaze() {
	string coords = "(" + convert(x) + ", " + convert(y) + ", " 
		+ convert(z) + ")";
	if ()
	return solution;
}