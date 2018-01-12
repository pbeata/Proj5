#ifndef _HOUSECLASS_H_
#define _HOUSECLASS_H_

#include <iostream>
#include <string>
using namespace std;

#include "RectangularEntityClass.h"
#include "ColorClass.h"
#include "MapClass.h"

//Some house-specific global constants..
const string HOUSE_TYPE_STR = "House";
const ColorClass HOUSE_COLOR = ColorClass(255, 0, 0);
const int HOUSE_VALUE_PER_PIXEL = 15000;

class HouseClass : public RectangularEntityClass
{
  private:
    int dollarValue;

  public:
    //The only ctor that is available - houses are described via a 
    //location they are to be positioned within a map and a value
    //of the house. Then the color of the house is 
    //maintained as a global constant specific to houses.
    HouseClass(
         const PixelLocationClass &inPixLoc,
         int inHouseValue
         ) : RectangularEntityClass(inPixLoc, HOUSE_COLOR)
    {
      dollarValue = inHouseValue;
    }

    //Simply creates a printable string from a house object, making sure
    //to only be responsible for those attributes directly associated
    //with the actual HouseClass, and leaving higher-level attributes to
    //higher-level classes.
    string toString() const
    {
      ostringstream oss;
      oss.clear();
      oss.str("");
      oss << HOUSE_TYPE_STR << " Value: " << dollarValue << " " <<
             MapEntityClass::toString();

      return (oss.str());
    } 

    //The required polymorphic interface for getting the type of a
    //map entity as a string.
    string getType() const
    {
      return HOUSE_TYPE_STR;
    }    

    //The HouseClass is printed as a square; thus the output of
    //the getNumRows and getNumCols functions will be equal
    //(i.e., a square is printed as n-by-n pixels, where n is the
    //output of either function here). 
    //  Size of house is proportional to value (1 pixel per 15000):
    //    value:     0-14999  -->  size 1x1 pixels
    //    value: 15000-29999  -->  size 2x2 pixels
    //    value: 30000-44999  -->  size 3x3 pixels (etc.)
    int getNumRows() const;
    int getNumCols() const;
};

#endif //_HOUSECLASS_H_
