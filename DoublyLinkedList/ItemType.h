//
// FILENAME :  ItemType.h
//
// DESCRIPTION :
//       Specification of ItemType class
//
// PUBLIC :
//       ItemType(int number)
//       void print()
//       void initialize(int number)
//       int getValue() const
//       Comparison compareTo(ItemType &item)
// 
// AUTHOR :    Michael Mazzone        START DATE :  28 Feb 2018
//

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>

enum Comparison {
  LESS,
  GREATER,
  EQUAL
};

class ItemType {

  public:
    ItemType(int number);
    void print();
    int getValue() const;
    Comparison compareTo(ItemType &item);

  private:
    int value;

};

#endif
