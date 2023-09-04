#include <iostream>
using namespace std;

struct Employee {
string name {};
int age {};
int wage {};

};

void printVariables (const Employee& employee) {
  cout << "This Employee name is " << employee.name << endl;
}

int main () {

  Employee joe { "joe", 25, 75000 };
  Employee frank { "frank", 39, 105000 };

  printVariables(joe);
  printVariables(frank);
  return 0;
  
}