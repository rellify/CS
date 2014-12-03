#include "to-students-09/Student_Code/AVL.h"
#include <iostream>

int main() {
	AVL test;
	test.add(0);
	test.add(1);
	test.remove(0);
	test.remove(1);
	test.add(0);
	test.add(1);
	test.print();
	return 0;
}