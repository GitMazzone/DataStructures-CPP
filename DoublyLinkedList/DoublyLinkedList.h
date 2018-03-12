//
// FILENAME :  DoublyLinkedList.h
//
// DESCRIPTION :
//       Specification of DoublyLinkedList class
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

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "ItemType.h"
#include "ListNode.h"

class DoublyLinkedList {

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(ItemType &newItem);
    void deleteItem(ItemType &delItem);
    int  getLength() const;
    void print();
    void findItem(ItemType &item);
    
  private:
    int length;
    ListNode * head;
    ListNode * current;
    bool found;
    bool moreToSearch;

};

#endif
