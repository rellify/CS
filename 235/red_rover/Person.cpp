// Spencer Wood
// CS 235 Fall 2014 Midterm

#include "Person.h"

Person::Person(string the_name, int the_strength, int the_speed) {
	name = the_name;
	strength = the_strength;
	speed = the_speed;
	leftPerson = NULL;
	rightPerson = NULL;
}

Person::~Person() {
	while (head != NULL) {
		removeHeadPerson();
	}
}