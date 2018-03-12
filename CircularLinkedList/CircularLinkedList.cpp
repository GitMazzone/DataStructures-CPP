//
// FILENAME :  CircularLinkedList.cpp
//
// DESCRIPTION :
//       Implementation of CircularLinkedList class.
//
// PUBLIC :
//       CircularLinkedList()
//       ~CircularLinkedList()
//       void insertItem(ItemType &newItem)
//       void deleteItem(ItemType &delItem)
//       int length() const
//       void print()
// 
// AUTHOR :    Michael Mazzone        START DATE :  28 Feb 2018
//

#include "CircularLinkedList.h"

using namespace std;

// Post: list is created
CircularLinkedList::CircularLinkedList() {

  length = 0;
  head   = nullptr;

}

// Pre:  list exists
// Post: all nodes are freed
CircularLinkedList::~CircularLinkedList() {

  ListNode * temp;

  if(length == 0) {
    return;
  }

  for(int i = 0; i < length; i++) {
    temp = head;
    if(temp->next == nullptr) {
      head = nullptr;
    } else {
      head = head->next;
    }
    delete temp;
  }

}

// Pre:  list exists
// Post: item is inserted into the list in sorted order
void CircularLinkedList::insertItem(ItemType &newItem) {

  ListNode * newNode;
  newNode = new ListNode(newItem);
  newNode->item = newItem;

  if(head != nullptr) {
    findItem(newItem);
    newNode->next = predLoc->next;
    predLoc->next = newNode;

    // Special case: inserting last node in list
    if(head->item.compareTo(newItem) == LESS) {
      head = newNode;
    }
  } else {
    // Special case: inserting into empty list
    head = newNode;
    newNode->next = newNode;
  }

  length++;

}

// Pre:  list exists and item is initialized
// Post: node containing the item is removed from the list
void CircularLinkedList::deleteItem(ItemType &delItem) {

  if(length == 0) {
    cout << "List is empty, nothing to delete." << endl;
    return;
  }

  findItem(delItem);

  if(!found) {
    cout << "Item not in list." << endl;
    return;
  }

  // Special case: deleting only node in list
  if(predLoc == current) {
    head = nullptr;
  } else {
    predLoc->next = current->next;
    // Special case: deleting last node in list
    if(current == head) {
      head = predLoc;
    }
  }

  delete current;
  length--;

}

// Pre:  list exists
// Post: returns length instance variable
int CircularLinkedList::getLength() const {
  
  return length;

}

// Pre:  list exists
// Post: items are printed to std-out based on ItemType implementation
void CircularLinkedList::print() {

  if(length == 0) {
    cout << "Circular linked list is empty." << endl;
    return;
  } else {

    current = head->next;

    do {
      cout << current->item.getValue() << " ";
      current = current->next;
    } while(current != head-> next);

    cout << endl;

  }

}

// Pre: list exists
// Post: if item in list, updates current location, predLoc, and found
// Note: use predLoc to insert or delete after using findItem
void CircularLinkedList::findItem(ItemType &item) {

  current = head->next;
  predLoc = head;
  found = false;
  moreToSearch = current != nullptr;

  while(moreToSearch && !found) {
    if(current->item.compareTo(item) == GREATER) {
      moreToSearch = false;
    } else if(current->item.compareTo(item) == EQUAL) {
      found = true;
    } else {
      predLoc = current;
      current = current->next;
      moreToSearch = current != head->next;
    }
  }

}
