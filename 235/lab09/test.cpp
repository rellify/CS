#include "to-students-09/Student_Code/AVL.h"
#include <iostream>

int main() {
	AVL test;
	test.add(3);
	test.add(1);
	test.add(7);
	test.add(2);
	test.add(5);
	test.add(8);
	test.add(4);
	test.add(9);
	test.add(6);
	test.print();
	test.prePrint();
	cout << "-------------------" << "\n";
	test.remove(2);
	test.print();
	test.prePrint();
	return 0;
}