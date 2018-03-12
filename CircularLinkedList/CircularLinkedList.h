//
// FILENAME :  CircularLinkedList.h
//
// DESCRIPTION :
//       Specification of CircularLinkedList class
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

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "ItemType.h"
#include "ListNode.h"

class CircularLinkedList {

  public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insertItem(ItemType &newItem);
    void deleteItem(ItemType &delItem);
    int  getLength() const;
    void print();
    void findItem(ItemType &item);

  private:
    int length;
    ListNode * head;
    ListNode * current;
    ListNode * predLoc;
    bool found;
    bool moreToSearch;

};

#endif
