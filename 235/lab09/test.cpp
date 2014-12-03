#include "to-students-09/Student_Code/AVL.h"
#include <iostream>

int main() {
	AVL test;
	for (int i = 0; i < 51; i++) {
		test.add(i);
		test.add(-i);
	}
	test.remove(0);
	test.remove(1);
	test.remove(-1);
	test.preOrderPrint();
	return 0;
}