#include "RoadClass.h"

int RoadClass::getNumRows() const
{
  int numRows;
  
  if (isVertical)
  {
    numRows = length;
  }
  else
  {
    numRows = numLanes * PIXELS_PER_LANE;
  }

  return numRows;
}

int RoadClass::getNumCols() const
{
  int numCols;

  if (isVertical)
  {
    numCols = numLanes * PIXELS_PER_LANE;
  }
  else
  {
    numCols = length;
  }

  return numCols;
}