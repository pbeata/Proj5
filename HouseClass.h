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
    ParkClass(
         const PixelLocationClass &inPixLoc,
         int inHouseValue
         ) : RectangularEntityClass(inPixLoc, HOUSE_COLOR)
    {
      dollarValue = inHouseValue;
      cout << dollarValue << endl;
    }

    string toString() const;
    string getType() const;
    int getNumRows() const;
    int getNumCols() const;

};

#endif //_HOUSECLASS_H_
