#ifndef _RECTANGULARENTITYCLASS_H_
#define _RECTANGULARENTITYCLASS_H_

#include "MapEntityClass.h"

class RectangularEntityClass : public MapEntityClass
{
  public:
    // ctor
    RectangularEntityClass(
         const PixelLocationClass &inPixLoc,
         const ColorClass &inColor
         )
    {
      MapEntityClass(inPixLoc, PARK_COLOR);
    }
    // one regular function to draw on our map is required:
    void drawOnMap();
    // four pure virtual functions are required:
    virtual string toString() const = 0;
    virtual string getType() const = 0;
    virtual int getNumRows() const = 0;
    virtual int getNumCols() const = 0;
};

#endif //_RECTANGULARENTITYCLASS_H_