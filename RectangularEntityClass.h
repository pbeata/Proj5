#ifndef _RECTANGULARENTITYCLASS_H_
#define _RECTANGULARENTITYCLASS_H_

#include "MapEntityClass.h"
#include "MapExceptionClass.h"

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
      bool hadAProblem;
      int numRows;
      int numCols;
      
      hadAProblem = false;
      
      // Determine the size of the rectangle to draw based on the 
      // implementations of these functions in the derived classes:
      numRows = getNumRows();
      numCols = getNumCols();

      // draw the rectangle on the map
      for (int iPixel = 0; iPixel < numRows; iPixel++)
      {
        for (int jPixel = 0; jPixel < numCols; jPixel++)
        {
          //catch exceptions inside the loops so we can continue
          //trying to set additional pixels as appropriate...
          try
          {
            mapObj->setMapPixel(location + PixelLocationClass(iPixel, jPixel), color);
          }
          catch (MapExceptionClass mapExcep)
          {
            cout << "ParkClass::drawOnMap caught exception: " <<
                    mapExcep.toString() << endl;
            hadAProblem = true;
          }
        }
      }

      //Our protocol is that if any problems were detected, this function
      //throws an exception after working through all the possible pixels,
      //so if there was a problem, throw an exception from here..
      if (hadAProblem)
      {
        ostringstream excOSS;

        excOSS.clear();
        excOSS.str("");
        excOSS << "Attempted to draw out of bounds";

        throw MapExceptionClass(excOSS.str());
      }

    }

    // Four pure virtual functions are required to be defined in 
    // any derived classes: 
    virtual string toString() const = 0;
    virtual string getType() const = 0;
    virtual int getNumRows() const = 0;
    virtual int getNumCols() const = 0;
};

#endif //_RECTANGULARENTITYCLASS_H_