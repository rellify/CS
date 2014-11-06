// Spencer Wood
// CS 235 Fall 2014 Midterm

#include <iostream>
#include <fstream>
#include "Team.h"

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

      // 1. Create roster

      if (selection == "1") { 
         fstream file;
         string file_name;
         cout << "Name of file: ";
         cin >> file_name;
         file.open(file_name.c_str());
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
         cout << "Roster imported." << endl;
      }

      // 2. View roster

      else if (selection == "2") {
         if (roster.empty()) {
            cout << "Roster Empty" << endl;
         }
         else {
            cout << "Current roster: ";
            roster.printTeam();
         }
      }

      // 3. Shuffle roster

      else if (selection == "3") {

      }

      // 4. Create teams

      else if (selection == "4") {
         if (roster.getSize() < 4) {
            cout << "Error: roster size too small (current size = " 
               << roster.getSize() << ")." << endl;
         }
         else {
            for (int i = roster.getSize()/2; i > 0; i--) {
               a_team.addPerson(roster.headName(), roster.headStrength(), 
                  roster.headSpeed());
               roster.removeHeadPerson();
               b_team.addPerson(roster.headName(), roster.headStrength(), 
                  roster.headSpeed());
               roster.removeHeadPerson();
            }
            cout << "Teams created." << endl;
         }
      }

      // 5. View teams

      else if (selection == "5") {
         if (a_team.empty()) {
            cout << "Teams empty." << endl;
         }
         else {
            cout << endl << "Team A:" << endl << endl;
            a_team.printInfo();
            cout << endl << "Team B:" << endl << endl;
            b_team.printInfo();
         }
      }

      // 6. User play

      else if (selection == "6") {
         cout << endl << "Team A:" << endl << endl;
         a_team.printTeam();
         cout << endl << "Person to call over: ";
      }

      // 7. Auto play

      else if (selection == "7") {
         
      }
   }
   return 0;
}