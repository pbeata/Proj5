#ifndef _ROADCLASS_H_
#define _ROADCLASS_H_

#include <iostream>
#include <string>
using namespace std;

#include "RectangularEntityClass.h"
#include "ColorClass.h"
#include "MapClass.h"

//Some road-specific global constants..
const string ROAD_TYPE_STR = "Road";
const ColorClass ROAD_COLOR = ColorClass(127, 127, 127);
const int PIXELS_PER_LANE = 3;

class RoadClass : public RectangularEntityClass
{
  private:
    int length;
    int numLanes;
    bool isVertical;

  public:
    //The only ctor that is available - roads are described via a 
    //location they are to be positioned within a map, a length
    //of the road, number of lanes, and whether it is vertical or not.
    //Then the color of the road is maintained as a global constant
    //specific to roads.
    RoadClass(
         const PixelLocationClass &inPixLoc,
         int inLength,
         int inNumLanes,
         bool inIsVertical
         ) : RectangularEntityClass(inPixLoc, ROAD_COLOR)
    {
      length = inLength;
      numLanes = inNumLanes;
      isVertical = inIsVertical;
    }

    //Simply creates a printable string from a road object, making sure
    //to only be responsible for those attributes directly associated
    //with the actual RoadClass, and leaving higher-level attributes to
    //higher-level classes.
    string toString() const
    {
      ostringstream oss;
      oss.clear();
      oss.str("");
      oss << ROAD_TYPE_STR << " Len: " << length;
      oss << " Lanes: " << numLanes; 
      oss << " Runs: ";  
      if (isVertical)
      {
        oss << "Vertical";
      }
      else
      {
        oss << "Horizontal";
      }
      oss << " " << MapEntityClass::toString();

      return (oss.str());
    }   

    //The required polymorphic interface for getting the type of a
    //map entity as a string.
    string getType() const
    {
      return ROAD_TYPE_STR;
    }

    //The RoadClass is printed as a rectangle; thus the output of
    //the getNumRows and getNumCols functions will require orientation
    //(i.e., vertical or horizontal) for the length and it will compute
    //number of pixels based on the number of lanes: 
    //  3 pixels width per lane
    int getNumRows() const;
    int getNumCols() const;

};

#endif //_ROADCLASS_H_
