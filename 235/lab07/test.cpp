#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ifstream file;
	file.open("test_import.txt");
	unsigned long long int ID;
	std::string hello;
	file >> ID;
	cout << ID << "\n";
	string name = "";
	getline(file, name);
	getline(file, name);
	cout << name << "\n";
	return 0;
}