#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int>reArrangeVectorElements(vector<int> &numbers, int y) {
    int temp;
  
    if (y > numbers.size()) {
        return numbers;
    } else if (numbers[y] < numbers[y+1]) {
        //if the number at a given index is less than the number right
        //next to it, swap them
        temp = numbers[y];
        numbers[y] = numbers[y+1];
        numbers[y+1] = temp;
    }
    //recursive function that calls itself by adding one to the
    //starting index y
    return reArrangeVectorElements(numbers, y + 1);
    
}

vector<int>maxNum(vector<int> &numbers, int x) {
    //if the size of the vector is 0, return 
    if (x == 0) {
        return numbers;
    //if there is at least one element in the vectoe, we will rearrange
    // it to from highest to lowest using the "rearrange function"
    } else if (x >= 1) {
        reArrangeVectorElements(numbers, 0);
    }
    return maxNum(numbers, x-1);
    
    }

int main() {

    ifstream input("input3.txt");
    ofstream output("output.txt");
    int inputNum;
    vector<int> numbers;
    while (input >> inputNum) {
        numbers.push_back(inputNum);
    }
     maxNum(numbers, numbers.size());

    for (int i = 0; i < numbers.size(); i++) {
        output << numbers[i];
      
    }


   
    return 0;
}




