#include <iostream>
#include <cmath>
using namespace std;

//Programmer: Andrew M. Morgan
//Date: April 2016
//Purpose: Implementation of non-insignificant member functions
//         of the ParkClass, which is documented in the class
//         definition file...

#include "ParkClass.h"
#include "MapClass.h"
#include "MapExceptionClass.h"

void ParkClass::drawOnMap(
     MapClass *mapObj
     ) const
{
  bool hadAProblem;
  int radius;
  hadAProblem = false;
  double distFromCenter;

  //Note: +1 because from 0 to the value should be 1 pixel, then
  //      an additional pixel for every multiple after that
  radius = numAcres / PARK_ACRES_PER_PIXEL + 1;

  for (int rInd = -radius; rInd <= radius; rInd++)
  {
    for (int cInd = -radius; cInd <= radius; cInd++)
    {
      //calculate how par this pixel offset is from center..
      distFromCenter = sqrt(rInd * rInd + cInd * cInd);

      //if its less than the computed radius, turn the pixel on..
      if (distFromCenter <= radius)
      {
        //catch exceptions inside the loops so we can continue
        //trying to set additional pixels as appropriate...
        try
        {
          mapObj->setMapPixel(location + PixelLocationClass(rInd, cInd), color);
        }
        catch (MapExceptionClass mapExcep)
        {
          cout << "ParkClass::drawOnMap caught exception: " <<
                  mapExcep.toString() << endl;
          hadAProblem = true;
        }
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
