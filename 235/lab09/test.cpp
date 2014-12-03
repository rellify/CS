#include "to-students-09/Student_Code/AVL.h"
#include <iostream>

int main() {
	AVL test;
	test.add(2);
	test.add(1);
	test.add(6);
	test.add(0);
	test.add(4);
	test.add(7);
	test.add(3);
	test.add(5);
	test.print();
	cout << "---------------" << "\n";
	test.remove(0);
	test.print();
	return 0;
}