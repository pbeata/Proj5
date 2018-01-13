#include "SchoolClass.h"

int SchoolClass::getNumRows() const
{
  int numRows;
  numRows = numStudents / SCHOOL_STUDENTS_PER_PIXEL + 1;
  return numRows;
}

int SchoolClass::getNumCols() const
{
  // SchoolClass is drawn as a square: numRows = numCols;
  return getNumRows();
}