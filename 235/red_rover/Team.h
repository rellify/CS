// Spencer Wood
// CS 235 Fall 2014 Midterm

#ifndef TEAM_H_
#define TEAM_H_

#include "Person.h"

using namespace std;

class Team {
private:
public:
	Team();
	~Team();
	Person* head;
	void addPerson(string the_name, int the_strength, int the_speed);
	void printTeam();
	bool empty();
};

#endif