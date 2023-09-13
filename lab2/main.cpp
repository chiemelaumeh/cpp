#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;


struct node {
string value;
node* next;
};

class LinkedList {
  private:
    node* head;

  public:
    LinkedList(){
    head = nullptr;
    }



    void ins_at_head(string val){

      node* temp = new node;
      temp->value = val;
      temp->next = nullptr;
      temp->next = head;
      head = temp;
    }

    void ins_at_tail(string val){
      node* temp = new node;
      temp->value = val;
      temp->next = nullptr;

      if(head == nullptr){
        head = temp;
        return;
      }

      node* cur = head;
      while(cur->next != nullptr){
        cur = cur->next;
      }
      cur->next = temp;
    }

    void ins_at_pos(string val, int pos){
      // int size = linkedListLength();
      // if(pos > size){
      //   return;
      // }

      node* temp = new node;
      temp->value = val;
      temp->next = nullptr;

      if(pos==0){
        temp->next = head;
        head = temp;
        return;
      }

      node* cur = head;
      node* prev = nullptr;

      for(int i = 0; i < pos; i++){
        if(cur->next == nullptr){
          return;
        }
        prev = cur;
        cur = cur->next;
      }
      prev->next = temp;
      temp->next = cur;
    }

    void rem_at_head(){
      if(head == nullptr){
        return;
      }
      node* temp = head;
      head = head->next;
      delete temp;
    }

    void rem_at_tail(){
      if(head == nullptr){
        return;
      }
      else if(head->next == nullptr) {
        node* temp = head;
        head = nullptr;
        delete temp;
        return;
      }
      node* cur = head;
      node* prev = nullptr;
      while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
      }

      prev->next = nullptr;
      delete cur;
    }

    void rem_at_pos(int p){
     

      if(head == nullptr){
        return;
      }
      else if(p == 0){
        node* temp = head;
        head = head->next;
        delete temp;
        return;
      }

      node* prev = nullptr;
      node* cur = head;
      for(int i = 0; i < p; i++)
        {
          if(cur->next == nullptr){
            return;
          }
          prev = cur;
          cur = cur->next;
        }
      prev->next = cur->next;
      delete cur;
    }

void print_head(ofstream &output){
  if(head != nullptr ){
    output << head->value<< endl;
  }
}

void print_pos(ofstream &output, int pos){
 
if(head == nullptr || pos < 0 ){
    return;
  }
  node* cur = head;
  for(int i = 0; i < pos; i++){
    if(cur->next == nullptr) {
      return;
    }
    cur = cur->next;
  }
    output << cur->value << endl;
}


void print_tail(ofstream &output){
  if (head != nullptr) {
    node* cur = head;

    while(cur->next != nullptr){
      cur = cur->next;
    }
    output << cur->value << endl;
  }
}


};


//DRIVER FUNCTION

int main(int argc, char *argv[])

{


    LinkedList wordList;
    ArgumentManager am(argc, argv);
    ifstream input(am.get("input"));
    ofstream output(am.get("output"));
    string inStr = "";
    string command = "";
    string position = "";
    string valStr = "";

    while (getline(input, inStr)) {
      inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
      inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());

      if(inStr.empty()){
            continue;
        }

        stringstream ss(inStr);
        ss >> command;

        if (command == "Insert")
        {
            ss >> position;

            if (position == "Head")
            {
                ss >> valStr;
                wordList.ins_at_head(valStr);
            }
            if (position == "Tail")
            {
                ss >> valStr;
                wordList.ins_at_tail(valStr);
            }
            if(position != "Head" && position != "Tail")
            {
                int index = stoi(position);
                ss >> valStr;
                wordList.ins_at_pos(valStr, index);
            }
        }

        else if (command == "Remove")
        {
            ss >> position;
            if (position == "Head")
            {
                wordList.rem_at_head();
            }
             if (position == "Tail")
            {
                wordList.rem_at_tail();
            }
          if (position != "Head" && position != "Tail")
           {
            int index = stoi(position);
            wordList.rem_at_pos(index);
          }
        }

        else if (command == "Print")
        {
            ss >> position;

            if (position == "[Head]")
            {
                wordList.print_head(output);
            }
           if (position == "[Tail]"){
                wordList.print_tail(output);
            }
          if (position != "[Head]" && position != "[Tail]") {
            position.erase(remove(position.begin(), position.end(), '['), position.end());
            position.erase(remove(position.begin(), position.end(), ']'), position.end());
            int index = stoi(position);
            wordList.print_pos(output, index);
          }
        }
    }



    input.close();
    output.close();
    return 0;
};

