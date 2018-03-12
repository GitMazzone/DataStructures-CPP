//
// FILENAME :  Main.cpp
//
// DESCRIPTION :
//       Entry point of DoublyLinkedList for Assignment2
//       Provides menu of specified options available to a doubly linked list
// 
// AUTHOR :    Michael Mazzone        START DATE :  28 Feb 2018
//

#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, const char* argv[]) {

  char choice = '0';
  DoublyLinkedList list;

  // Open and loop through input file and populate vector

  vector<int> numbers;
  ifstream inputFile(argv[1], ios::in);
  int number = 0;
  while(inputFile >> number) {
    numbers.push_back(number);
  }
  for(int i = 0; i < numbers.size(); i++) {
    ItemType newItem(numbers[i]);
    list.insertItem(newItem);
  }

  cout << "\nInitial sorted doubly linked list: " << endl;
  list.print();

  cout << "\n============================================================================" << endl;
  cout << "Please type a valid menu option letter and press enter." << endl;
  cout << "insert (i), delete (d), length (l), print (p), additivepair (a), quit (q)" << endl;
  cout << "============================================================================" << endl;

  while(choice != 'q') {

    cout << "\nEnter a command: ";
    cin >> choice;

    switch(choice) {
      case 'q':
        break;
      case 'i': {
        cout << "Number to insert: ";
        cin >> number;
        ItemType newItem(number);
        list.insertItem(newItem);
        list.print();
        break;
      }
      case 'd': {
        cout << "Number to delete: ";
        cin >> number;
        ItemType delItem(number);
        list.deleteItem(delItem);
        list.print();
        break;
      }
      case 'l': {
        cout << "List length: " << list.getLength() << endl;
        list.print();
        break;
      }
      case 'p': {
        list.print();
        break;
      }
      case 'a': {
        // TODO: extra credit
      }
    }

  }

  cout << "\nDon't forget to `$ make clean` when you're done!" << endl;

}
