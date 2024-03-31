#include <cmath>

class Point2D
{
private:
public:
    int _x, _y;
    Point2D(float x, float y);
    ~Point2D();
    bool equals(Point2D p);
};
