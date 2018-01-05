#ifndef _RECTANGULARENTITYCLASS_H_
#define _RECTANGULARENTITYCLASS_H_

#include "MapEntityClass.h"

class RectangularEntityClass : public MapEntityClass
{
  public:

    RectangularEntityClass(
         const PixelLocationClass &inPixLoc,
         const ColorClass &inColor
         ) : MapEntityClass(inPixLoc, inColor)
    {
      printf("NEW RECTANGLE\n");
    }

    //The required polymorphic interface for drawing a map entity onto
    //a map - this implementation draws a rectangular object as a 
    //on the map being pointed to by the parameter.
    void drawOnMap(MapClass *mapObj) const
    {
      // placeholder until I fill this
    }

    // four pure virtual functions are required:
    /*
    virtual string toString() const = 0;
    virtual string getType() const = 0;
    virtual int getNumRows() const = 0;
    virtual int getNumCols() const = 0;
    */
};

#endif //_RECTANGULARENTITYCLASS_H_