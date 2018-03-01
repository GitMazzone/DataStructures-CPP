//
// FILENAME :    ListNode.h
//
// DESCRIPTION :
//       Struct that forms the node of a singly linked list.
//
// PUBLIC :
//       DataType item
//       ListNode *next
//       explicit ListNode(DataType &item) : item(item) {}
//
// NOTES :
//       Consists of the item data and a pointer to the next node.
// 
// AUTHOR :    Michael Mazzone        START DATE :    05 Feb 2018
//

#ifndef LISTNODE_H
#define LISTNODE_H

#include "DataType.h"

struct ListNode {

  DataType item;    // node's data
  ListNode * next;  // node's ptr to next node
  explicit ListNode(DataType &item) : item(item) {};
  
};

#endif
