#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "to-students/Student_Code/Student.h"

using namespace std;

int main() {
	Student* test = new Student();
	test->ID = 123456;
	test->name = "Spencer";
	test->address = "the moon";
	test->phone_number = "720yourmom";
	test->grade_total = 4;
	test->number_of_classes = 2;
	cout << test->toString() << "\n";

	double GPA = 4;
	stringstream precise;
	precise << fixed << setprecision(2) << GPA;
	cout << precise.str() << "\n";
	return 0;
}