//
// FILENAME :  ListNode.h
//
// DESCRIPTION :
//       Struct that forms the node of a circular linked list.
//
// PUBLIC :
//       DataType item
//       ListNode *next
//       explicit ListNode(DataType &item) : item(item) {}
//
// NOTES :
//       Consists of the item data and a pointer to the next node.
// 
// AUTHOR :    Michael Mazzone        START DATE :  28 Feb 2018
//

#ifndef LISTNODE_H
#define LISTNODE_H

#include "ItemType.h"

struct ListNode {

  ItemType item;    // node's data
  ListNode * next;  // node's ptr to next node
  ListNode * back;  // node's ptr to previous node
  explicit ListNode(ItemType &item) : item(item) {};
  
};

#endif
