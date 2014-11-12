#include <iostream>

using namespace std;

int main() {
   int a = 6;
   int b = 9;
   a %= b; 
   cout << a << endl;

   int c = 6;
   int d = 9;
   c ^= d;
   d ^= c;
   c ^= d;
   cout << "C = " << c << ", " << "D = " << d << endl;
   return 0;
}
