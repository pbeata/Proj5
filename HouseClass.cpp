#include "HouseClass.h"

int HouseClass::getNumRows() const
{
  int numRows;
  numRows = dollarValue / HOUSE_VALUE_PER_PIXEL + 1;
  return numRows;
}

int HouseClass::getNumCols() const
{
  // HouseClass is drawn as a square: numRows = numCols;
  return getNumRows();
}