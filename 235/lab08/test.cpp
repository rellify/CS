#include <iostream>
#include "QS.h"

using namespace std;

int main() {
	QS test;
	test.createArray(20);
	test.addToArray(10);
	test.addToArray(10);
	test.addToArray(24);
	test.addToArray(37);
	test.addToArray(6);
	test.addToArray(100);
	test.addToArray(101);
	test.addToArray(45);
	test.addToArray(245);
	test.addToArray(23);
	test.addToArray(2);
	test.addToArray(67);
	test.addToArray(81);
	test.addToArray(15);
	test.addToArray(2);
	test.addToArray(2);
	test.addToArray(145);
	test.addToArray(2);
	test.addToArray(0);
	test.addToArray(79);
	cout << "Before sort: " << test.getArray() << "\n";
	test.sortAll();
	cout << "After sort: " << test.getArray() << "\n";
	}