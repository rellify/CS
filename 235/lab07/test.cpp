#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "to-students/Student_Code/Student.h"
#include "to-students/Student_Code/GPA.h"

using namespace std;

int main() {
	GPA hello;
	bool tester = hello.importStudents("to-students/Files/classListMap_Small.txt", "to-students/Files/classListSet_Small.txt");
	if (!tester) {
		cout << "Failed." << "\n";
	}
	return 0;
}