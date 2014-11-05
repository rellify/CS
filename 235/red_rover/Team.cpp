// Spencer Wood
// CS 235 Fall 2014 Midterm

#include <iostream>
#include "Team.h"

Team::Team() {
	head = NULL;
}

Team::~Team() {}

void Team::addPerson(string the_name, int the_strength, int the_speed) {
	if (head == NULL) {
		Person* newPerson = new Person(the_name, the_strength, the_speed);
		head = newPerson;
	}
	else {
		Person* go = head;
		Person* previous;
		while (go != NULL) {
			previous = go;
			go = go->rightPerson;
		}
		Person* newPerson = new Person(the_name, the_strength, the_speed);
		previous->rightPerson = newPerson;
		newPerson->leftPerson = previous;
	}
}

void Team::printTeam() {
	Person* go = head;
	while (go != NULL) {
		cout << go->name << endl;
		go = go->rightPerson;
	}
}

bool Team::empty() {
	if (head == NULL) {
		return true;
	}
	return false;
}