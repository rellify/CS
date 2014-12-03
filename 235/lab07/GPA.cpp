#include "GPA.h"
#include <fstream>
#include <iostream>

GPA::GPA() {}

GPA::~GPA() {}

map<unsigned long long int, StudentInterface*> GPA::getMap() {
	return studentMap;
}

set<StudentInterface*, Comparator> GPA::getSet() {
	return studentSet;
}

bool GPA::importStudents(string mapFileName, string setFileName) {
	fstream map_file;
	fstream set_file;
	map_file.open(mapFileName.c_str());
	set_file.open(setFileName.c_str());
	if (!map_file || !set_file) {
		cout << "Invalid files" << "\n";
		return false;
	}
	string temp = "";
	while (getline(map_file, temp)) {
		
	}
	StudentInterface* temp = new Student()
	studentMap[ID] = 
	
	return true;
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