//
// FILENAME :    DataType.h
//
// DESCRIPTION :
//       Data type for list operations to be performed on.
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

#ifndef DATATYPE_H
#define DATATYPE_H

enum Comparison {
  LESS,
  GREATER,
  EQUAL
};

class DataType {

  public:
    explicit DataType(int value);
    Comparison compareTo(DataType &item);
    int getValue() const;

  private:
    int value;

};

#endif
