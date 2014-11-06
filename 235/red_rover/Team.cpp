// Spencer Wood
// CS 235 Fall 2014 Midterm

#include <iostream>
#include "Team.h"

Team::Team() {
	head = NULL;
	size = 0;
}

Team::~Team() {}

void Team::addPerson(string name, int strenth, int speed) {
	if (head == NULL) {
		Person* newPerson = new Person(name, strenth, speed);
		head = newPerson;
		size++;
	}
	else {
		Person* go = head;
		Person* previous;
		while (go != NULL) {
			previous = go;
			go = go->rightPerson;
		}
		Person* newPerson = new Person(name, strenth, speed);
		previous->rightPerson = newPerson;
		newPerson->leftPerson = previous;
		size++;
	}
}


void Team::printTeam() {
	Person* go = head;
	while (go->rightPerson != NULL) {
		cout << go->name << ", ";
		go = go->rightPerson;
	}
	cout << go->name << endl;
	go = NULL;
}

void Team::printInfo() {
	Person* go = head;
	while (go != NULL) {
		cout << go->name << ": " << go->strength << ", " << go->speed << endl;
		go = go->rightPerson;
	}
}

void Team::removeHeadPerson() {
	Person* temp = head;
	head = temp->rightPerson;
	delete temp;
	size--;
}

string Team::headName() {
	return head->name;
}

int Team::headStrength() {
	return head->strength;
}

int Team::headSpeed() {
	return head->speed;
}

int Team::getSize() {
	return size;
}

bool Team::empty() {
	if (size == 0) {
		return true;
	}
	return false;
}