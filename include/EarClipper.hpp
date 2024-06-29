#include <vector>
#include <cmath>
#include <stdio.h>
#include <iostream>

#include "Triangle.hpp"
#include "Point2D.hpp"

class EarClipper
{
private:
    std::vector<Point2D> _vertices;

    float getAngle(Point2D p0, Point2D p1, Point2D p2);
    bool isPointInTriangle(Point2D p0, Point2D p1, Point2D p2);
public:
    EarClipper(std::vector<Point2D> vertices);
    ~EarClipper();
    std::vector<Triangle> triangulate();
};
