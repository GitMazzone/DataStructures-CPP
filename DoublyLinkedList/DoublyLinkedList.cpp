//
// FILENAME :  DoublyLinkedList.cpp
//
// DESCRIPTION :
//       Implementation of DoublyLinkedList class.
//
// PUBLIC :
//       DoublyLinkedList()
//       ~DoublyLinkedList()
//       void insertItem(ItemType &newItem)
//       void deleteItem(ItemType &delItem)
//       int length() const
//       void print()
//       void findItem(ItemType &item);
// 
// AUTHOR :    Michael Mazzone        START DATE :  28 Feb 2018
//

#include "DoublyLinkedList.h"

using namespace std;

// Post: list is created
DoublyLinkedList::DoublyLinkedList() {

  length = 0;
  head   = nullptr;

}

// Pre:  list exists
// Post: all nodes are freed
DoublyLinkedList::~DoublyLinkedList() {

  ListNode * temp;

  if(length == 0) {
    return;
  }

  while(head != nullptr) {
    temp = head;
    head = head->next;
    delete temp;
  }

}

// Pre:  list exists
// Post: item is inserted into the list in sorted order
void DoublyLinkedList::insertItem(ItemType &newItem) {

  ListNode * newNode;
  newNode = new ListNode(newItem);
  newNode->item = newItem;

  if(head != nullptr) {

    findItem(newItem);
    
    if(current != nullptr) {
      if(current->back == nullptr) {
        // Inserting new head
        newNode->back = nullptr;
        newNode->next = head;
        head->back = newNode;
        head = newNode;
      } else {
        // General case insert
        // Insert and update newNode ptrs
        newNode->back = current->back;
        newNode->next = current;
        // Update surrounding node ptrs
        current->back->next = newNode;
        current->back = newNode;
      }
    } else {
      // Special case: inserting last node in list
      // Loop to end of list
      current = head;
      moreToSearch = true;
      while(current->next != nullptr) {
        current = current->next;
      }
      // Insert and update newNode ptrs
      newNode->back = current;
      newNode->next = nullptr;
      // Update predecessor node ptr
      current->next = newNode;
    } 

  } else { 
    // Special case: inserting into empty list
    head = newNode;
    newNode->back = nullptr;
    newNode->next = nullptr;
  }

  length++;

}

// Pre:  list exists and item is initialized
// Post: node containing the item is removed from the list
void DoublyLinkedList::deleteItem(ItemType &delItem) {

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
  if(current->back == nullptr && current->next == nullptr) {
    head = nullptr;
  } else {
    // Special case: deleting last node in list
    if(current->next == nullptr) {
      current->back->next = nullptr;
    } else {
      if(current->back == nullptr) {
        // deleting head node
        head = current->next;
        current->next->back = nullptr;
      } else {
        // all cases work fine if just ./main
        // only some don't work near front of list if using input.txt
        current->back->next = current->next;
        current->next->back = current->back;
      }
    }
  }

  delete current;
  length--;

}

// Pre:  list exists
// Post: returns length instance variable
int DoublyLinkedList::getLength() const {

  return length;

}

// Pre:  list exists
// Post: items are printed to std-out based on ItemType implementation
void DoublyLinkedList::print() {

  if(length == 0) {
    cout << "Doubly linked list is empty." << endl;
    return;
  } else {

    current = head;

    do {
      cout << current->item.getValue() << " ";
      current = current->next;
    } while (current != nullptr);

  }

}

// Pre: list exists
// Post: if item in list, updates current and found
// Note: use current to insert or delete after using findItem
void DoublyLinkedList::findItem(ItemType &item) {

  current = head;
  found = false;
  moreToSearch = current != nullptr;

  while(moreToSearch && !found) {
    if(current->item.compareTo(item) == GREATER) {
      moreToSearch = false;
    } else if(current->item.compareTo(item) == EQUAL) {
      found = true;
    } else {
      current = current->next;
      moreToSearch = current != nullptr;
    }
  }

}
