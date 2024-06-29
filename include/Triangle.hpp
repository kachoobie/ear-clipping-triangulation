#include "Point2D.hpp"

class Triangle
{
private:
public:
    Point2D _p1, _p2, _p3;
    Triangle(Point2D p1, Point2D p2, Point2D p3);
    Triangle();
    ~Triangle();
    bool equals(Triangle other);
};


