#ifndef _SCHOOLCLASS_H_
#define _SCHOOLCLASS_H_

#include <iostream>
#include <string>
using namespace std;

#include "RectangularEntityClass.h"
#include "ColorClass.h"
#include "MapClass.h"

//Some school-specific global constants..
const string SCHOOL_TYPE_STR = "School";
const ColorClass SCHOOL_COLOR = ColorClass(63, 63, 255);
const int SCHOOL_STUDENTS_PER_PIXEL = 50;

class SchoolClass : public RectangularEntityClass
{
  private:
    int numStudents;

  public:
    //The only ctor that is available - schools are described via a 
    //location they are to be positioned within a map and the number
    //of students in the school. Then the color of the school is 
    //maintained as a global constant specific to schools.
    SchoolClass(
         const PixelLocationClass &inPixLoc,
         int inNumStudents
         ) : RectangularEntityClass(inPixLoc, SCHOOL_COLOR)
    {
      numStudents = inNumStudents;
    }

    //Simply creates a printable string from a school object, making sure
    //to only be responsible for those attributes directly associated
    //with the actual SchoolClass, and leaving higher-level attributes to
    //higher-level classes.
    string toString() const
    {
      ostringstream oss;
      oss.clear();
      oss.str("");
      oss << SCHOOL_TYPE_STR << " #Students: " << numStudents << " " <<
             MapEntityClass::toString();

      return (oss.str());
    }     

    //The required polymorphic interface for getting the type of a
    //map entity as a string.
    string getType() const
    {
      return SCHOOL_TYPE_STR;
    }     

    //The SchoolClass is printed as a square; thus the output of
    //the getNumRows and getNumCols functions will be equal
    //(i.e., a square is printed as n-by-n pixels, where n is the
    //output of either function here). 
    //  Size of school is proportional to the number of students 
    //  (1 pixel per 50 students):
    //    value:   0-49   -->  size 1x1 pixels
    //    value:  50-99   -->  size 2x2 pixels
    //    value: 100-149  -->  size 3x3 pixels (etc.)
    int getNumRows() const;
    int getNumCols() const;    

};

#endif //_SCHOOLCLASS_H_
