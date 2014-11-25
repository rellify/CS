#include "GPA.h"

GPA::GPA() {}

GPA::~GPA() {}

map<unsigned long long int, StudentInterface*> GPA::getMap() {
	return studentMap;
}

set<StudentInterface*, Comparator> GPA::getSet() {
	return studentSet;
}

bool GPA::importStudents(string mapFileName, string setFileName) {
	return false;
}

bool GPA::importGrades(string fileName) {
	return false;
}

string GPA::querySet(string fileName) {
	return "";
}

string GPA::queryMap(string fileName) { 
	return "";
}

void GPA::clear() {
}