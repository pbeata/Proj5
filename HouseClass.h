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
    /*
    string toString() const
    {
      ostringstream oss;
      oss.clear();
      oss.str("");
      oss << HOUSE_TYPE_STR << " Value: " << dollarValue << " " <<
             RectangularEntityClass::toString();

      return (oss.str());
    } 
    */   

    //The required polymorphic interface for getting the type of a
    //map entity as a string.
    string getType() const
    {
      return HOUSE_TYPE_STR;
    }    

    /*
    string toString() const;
    int getNumRows() const;
    int getNumCols() const;
    */
};

#endif //_HOUSECLASS_H_
