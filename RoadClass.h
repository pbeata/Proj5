#ifndef _ROADCLASS_H_
#define _ROADCLASS_H_

class RoadClass : public RectangularEntityClass
{
  private:
    int length;
    int numLanes;
    bool isVertical;

  public:
    void setTest();

};

#endif //_ROADCLASS_H_
