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
	int size;
	void addPerson(string name, int strength, int speed);
	void printTeam();
	void printInfo();
	void removeHeadPerson();
	string headName();
	int headStrength();
	int headSpeed();
	int getSize();
	bool empty();
};

#endif