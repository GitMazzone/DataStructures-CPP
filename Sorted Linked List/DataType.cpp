//
// FILENAME :    DataType.cpp
//
// DESCRIPTION :
//       Implementation of DataType class.
//
// PUBLIC :
//       explicit DataType(int value)
//       Comparison compareTo(DataType &item)
//       int getValue() const
//
// NOTES :
//       DataType abstracts the list data by providing comparison
//       and get functionality. Acts as a helper class to ListNode.
// 
// AUTHOR :    Michael Mazzone        START DATE :    05 Feb 2018
//

#include "DataType.h"

// Post: DataType object is created
DataType::DataType(int newValue) {
  value = newValue;
}

// Pre: @item is initialized
// Post: returns enum indicating whether caller is LESS, 
//       GREATER, or EQUAL to item
Comparison DataType::compareTo(DataType &item) {
  if(value < item.value)
    return LESS;
  else if(value > item.value) 
    return GREATER;
  else 
    return EQUAL;
}

// Pre: DataType object has been initialized
// Post: return value of instance variable
int DataType::getValue() const {
  return value;
}
