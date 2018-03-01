//
// FILENAME :    Main.cpp
//
// DESCRIPTION :
//       Entry point of Assignment1. Provides menu of all options available
//       to a sorted, singly-linked list. 
// 
// AUTHOR :    Michael Mazzone        START DATE :    05 Feb 2018
//

#include "SortedLinkedList.h"

using namespace std;

// Main entry point of Assignment1
int main(int argc, const char* argv[]) {

  char choice = '0';
  SortedLinkedList list;

  // Open and loop through input file and populate vector
  vector<int> numbers;
  ifstream inputFile(argv[1], ios::in);  // Creates an input file stream
  int number = 0;                        // Holds each number as it's read
  while(inputFile >> number) {           // Loop until end of file
    numbers.push_back(number);
  }
  // Loop through vector and populate initial sorted linked list
  for(int i = 0; i < numbers.size(); i++) {
    DataType newValue(numbers[i]);
    list.insertItem(newValue);
  }

  cout << "Initial sorted linked list: " << endl;
  list.displayList();
  cout << endl;
  cout << "========================================================" << endl;
  cout << "Please type a valid menu option letter and press enter." << endl;
  cout << "(i) INSERT" << endl;
  cout << "(d) DELETE" << endl;
  cout << "(s) SEARCH" << endl;
  cout << "(n) ITR_NEXT" << endl;
  cout << "(r) RESET_ITR" << endl;
  cout << "(p) PRINT_ALL" << endl;
  cout << "(l) LENGTH" << endl;
  cout << "(c) CLEAR_ALL" << endl;
  cout << "(b) PAIR_SWAP" << endl;
  cout << "(q) QUIT" << endl;
  cout << "========================================================" << endl;
  cout << endl;

  while(choice != 'q') {
    cout << "\nCommand: ";
    cin >> choice;

    switch(choice) {
      case 'q':
        break;
      case 'i': {
        list.displayList();
        cout << "\nEnter number: ";
        cin >> number;
        DataType newValue(number);
        list.insertItem(newValue);
        list.displayList();
        break;
      }
      case 'd': {  // TODO: loop until all instances are deleted
        list.displayList();
        cout << "\nEnter number: ";
        cin >> number;
        DataType delItem(number);
        list.deleteItem(delItem);
        list.displayList();
        break;
      }
      case 's': {
        cout << "Enter a value to search: " << endl;
        cin >> number;
        DataType findItem(number);
        if(list.searchItem(findItem) != -1) {
          cout << "Index of the item is: " << list.searchItem(findItem) << endl;
        }
        break;
      }
      case 'n':
        list.getNextItem();
        break;
      case 'r':
        list.resetIterator();
        break;
      case 'p':
        list.displayList();
        break;
      case 'l':
        cout << "List length is: " << list.length() << endl;
        break;
      case 'c':
        list.clear();
        break;
      case 'b':
        // do pair_swap
        break;
    }

  }

  cout << "\nThanks for testing!" << endl;
  cout << "Don't forget to `$ make clean`" << endl;

}
