#include <sstream>
#include "Student.h"

Student::Student(unsigned long long int new_ID, string new_name) {
	ID = new_ID;
	name = new_name;
	grade_total = 0;
	number_of_classes = 0;
}
Student::~Student() {}

unsigned long long int Student::getID() {
	return ID;	
}

string Student::getName() {
	return name;
}

string Student::getGPA() {
	GPA = grade_total / number_of_classes;
	stringstream convert;
	convert << GPA;
	string result = convert.str();
	return result; 
}