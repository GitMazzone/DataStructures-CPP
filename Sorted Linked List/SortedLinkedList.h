//
// FILENAME :    SortedLinkedList.h
//
// DESCRIPTION :
//       Sorted singly-linked list struct.
//
// PUBLIC :
//       SortedLinkedList()
//       ~SortedLinkedList()
//       int length() const
//       void insertItem(DataType &newItem)
//       void deleteItem(DataType &delItem)
//       int searchItem(DataType &wantedItem)
//       void clear()
//       void getNextItem()
//       void resetIterator()
//       void pairwiseSwap()
//       void displayList()
// 
// AUTHOR :    Michael Mazzone        START DATE :    05 Feb 2018
//

#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "DataType.h"
#include "ListNode.h"

struct SortedLinkedList {

  public:
    SortedLinkedList();
    ~SortedLinkedList();
    int  length() const;
    void insertItem(DataType &newItem);
    void deleteItem(DataType &delItem);
    int  searchItem(DataType &wantedItem);
    void clear();
    void getNextItem();
    void resetIterator();
    void pairwiseSwap();  // Extra credit

    // Additional helper methods
    void displayList();

  private:
    int count;
    ListNode * head;
    ListNode * currentPosition;

};

#endif
