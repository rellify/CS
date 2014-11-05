// Spencer Wood
// CS 235 Fall 2014 Midterm

#include <iostream>
#include <fstream>
#include "Team.h"
#include "Person.h"

void printMenu() {
   cout << "------------------" << endl;
   cout << "1. Create Roster" << endl;
   cout << "2. View Roster" << endl;
   cout << "3. Shuffle Roster" << endl;
   cout << "4. Create Teams" << endl;
   cout << "5. View Teams" << endl;
   cout << "6. User Play" << endl;
   cout << "7. Auto Play" << endl;
   cout << "8. Quit" << endl;
   cout << "------------------" << endl;
   cout << "Please make a selection: ";
   return;
}

bool menuCheck(string selection) {
   string lookup_table [8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
   for (int i = 0; i < 8; i++) {
      if (selection == lookup_table[i]) {
         return true;
      }
   }
   return false;
}

int main() {
   string selection;
   Team roster;
   Team a_team;
   Team b_team;
   while (selection != "8") {
      printMenu();
      cin >> selection;
      while (!menuCheck(selection)) {
         cout << "Please make a valid selection (1-8): ";
         cin >> selection;
      }

      // Create roster

      if (selection == "1") { 
         fstream file;
         string file_name;
         cout << "Name of file: ";
         cin >> file_name;
         file.open(file_name);
         if (!file) {
            cout << "Error: invalid file name." << endl;
         }
         else {
            while (!file.eof()) {
               string name;
               int strength;
               int speed;
               file >> name;
               file >> strength;
               file >> speed;
               roster.addPerson(name, strength, speed);
            }
         }
      }

      // View roster

      if (selection == "2") {
         if (roster.empty()) {
            cout << "Roster Empty" << endl;
         }
         else {
            roster.printTeam();
         }
      }
   }
   return 0;
}