#include <vector>
#include <cmath>

#include "Point2D.hpp"

class EarClipper
{
private:
    std::vector<Point2D> _vertices;

    float getAngle(Point2D shared, Point2D p1, Point2D p2);
public:
    EarClipper(std::vector<Point2D> vertices);
    ~EarClipper();
    void triangulate();
};
