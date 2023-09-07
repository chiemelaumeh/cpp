#include <iostream>
using namespace std;

struct Point {
  int value;
  Point *next;
};

class Line {
  private:
    Point *head;
  public:
    Line () {
      head = nullptr;
    }

    void insertAtBeginning(int a) {
      Point *temp = new Point;

      temp->value = a;
      temp->next=nullptr;
      temp->next=head;

      head = temp;

      // cout << temp;
    


    }

    void printElements() {
      Point *curr = head;
      while (curr !=NULL) {
        cout << curr->value<< " --> ";
        curr = curr->next;
      };
      cout << endl;

    };



};

int main () {
  Line greenLine;
  greenLine.insertAtBeginning(2);
  greenLine.insertAtBeginning(4);
  greenLine.printElements();

  return 0;
}