//
// FILENAME :    SortedLinkedList.cpp
//
// DESCRIPTION :
//       Implementation of SortedLinkedList struct, a singly-linked list.
//
// PUBLIC :
//       SortedLinkedList()
//       ~SortedLinkedList()
//       int length() const
//       void insertItem(DataType &item)
//       void deleteItem(DataType &item)
//       int searchItem(DataType &item)
//       void clear()
//       void getNextItem()
//       void resetIterator()
//       void pairwiseSwap()
//       void displayList()
// 
// AUTHOR :    Michael Mazzone        START DATE :    05 Feb 2018
//

#include "SortedLinkedList.h"

using namespace std;

// Post: list is created
SortedLinkedList::SortedLinkedList() {

  count = 0;
  head = NULL;

}

// Pre: list exists
// Post: all nodes in list are freed
SortedLinkedList::~SortedLinkedList() {

  ListNode * temp;

  while(head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }

}

// Pre: list exists
// Post: return count instance variable
int SortedLinkedList::length() const {

  return count;

}

// Pre: list exists
// Post: item inserted in sorted order
//       Special case: if first item, set as head
void SortedLinkedList::insertItem(DataType &newItem) {

  ListNode * newNode;          // ptr to node being inserted
  ListNode * predLoc;          // ptr to node directly before new node
  ListNode * location;         // ptr to current node
  bool moreToSearch; 

  predLoc = NULL;
  location = head;
  moreToSearch = location != NULL;

  // Loop until currentPosition item value is not less than newItem's value
  while(moreToSearch) {
    if(location->item.compareTo(newItem) == LESS) {
      predLoc = location;
      location = location->next;
      moreToSearch = location != NULL;
    } else {
      moreToSearch = false;
    }
  }

  newNode = new ListNode(newItem);
  newNode->item = newItem;

  // First item special case
  if(predLoc == NULL) {
    newNode->next = head;
    head = newNode;
  } else {  // Else insert as normal
    newNode->next = location;
    predLoc->next = newNode;
  }

  count++;

}

// Pre: list exists, item exists
// Post: node containing item is removed from list
//       Special case: deleting first item, TODO
//       Special case: deleting only item, TODO
void SortedLinkedList::deleteItem(DataType &delItem) {

  if(count == 0) {
    cout << "Nothing to delete." << endl;
    return;
  }

  ListNode * predLoc;          // ptr to node directly before new node
  ListNode * location;         // ptr to current node
  bool moreToSearch; 

  predLoc = NULL;
  location = head;
  moreToSearch = location != NULL; 

  // Loop until currentPosition item value is equal to delItem's value
  while(moreToSearch) {
    if(location->item.compareTo(delItem) == GREATER) {
      moreToSearch = false;
    } else if(location->item.compareTo(delItem) == LESS) {
      predLoc = location;
      location = location->next;
      moreToSearch = location != NULL;
    } else {
      moreToSearch = false;
    }
  }

  // First item special case
  if(predLoc == NULL) {
    head = location->next;
    delete location;
    count--;
  } else if(count == 1) {  // Only item special case
    head = NULL;
    delete location;
    count--;
  } else {  // Else delete as normal
    predLoc->next = location->next;
    delete location;
    count--;
  }

}

// Pre: list exists
// Post: returns index of node containing item
int SortedLinkedList::searchItem(DataType &wantedItem) {

  int index = 0;
  ListNode * predLoc;          // ptr to node directly before new node
  ListNode * location;         // ptr to current node
  bool moreToSearch; 
  bool found = false;

  predLoc = NULL;
  location = head;
  moreToSearch = location != NULL; 

  if(count == 0) {  // Empty list
    cout << "No items in list." << endl;
    return -1;
  } else if(count == 1){  // List with 1 item
    return index;
  } else {  // Any other list
    while(moreToSearch && !found) {  // Get index of item
      if(location->item.compareTo(wantedItem) == GREATER) {
        cout << "Item not in list." << endl;
        return -1; 
      } else if(location->item.compareTo(wantedItem) == LESS) {
        index++;
        location = location->next;
        moreToSearch = location != NULL;
      } else if(location->item.compareTo(wantedItem) == EQUAL) {
        found = true;
        moreToSearch = false;
      }
    }
  }
  if(!found) {
    cout << "Item not in list." << endl;
    return -1;
  }

  return index;

}

// Pre: list exists
// Post: list contains no items, length (count) is 0, ptr mem freed
void SortedLinkedList::clear() {

  if(count == 0) {
    cout << "Nothing to clear." << endl;
    return;
  }

  ListNode * location;
  location = head;

  while(length() > 0) {
    deleteItem(location->item);
  }

  cout << "List cleared" << endl;

}

// Pre: list exists and has not been modified since last call
// Post: displays next item in the list, and when end is reached, next is head
void SortedLinkedList::getNextItem() {

  if(count == 0) {
    cout << "List is empty." << endl;
    return;
  }

  if(currentPosition == NULL) {
    currentPosition = head;
    cout << "Next value is: " << currentPosition->item.getValue() << endl;
  } else if(currentPosition->next == NULL) {
    resetIterator();
  } else {
    currentPosition = currentPosition->next;
    cout << "Next value is: " << currentPosition->item.getValue() << endl;
  }

}

// Pre: list exists
// Post: resets iterator position to head
void SortedLinkedList::resetIterator() {

  currentPosition = NULL;
  cout << "Iterator reset." << endl;

}

// Pre: list exists
// Post: items are sorted, adjacent pair nodes swapped according to their index
void SortedLinkedList::pairwiseSwap() {
  // TODO
}

void SortedLinkedList::displayList() {

  ListNode * location;
  location = head;

  if(count == 0) {
    cout << "List is empty." << endl;
  } else {
    for(int i = 0; i < count; i++) {
      cout << location->item.getValue() << " ";
      location = location->next;
    }
  }
  
}
