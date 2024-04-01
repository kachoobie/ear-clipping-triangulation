#include "EarClipper.hpp"

EarClipper::EarClipper(std::vector<Point2D> vertices)
{
    this->_vertices = vertices;
}

EarClipper::~EarClipper()
{
}

void EarClipper::triangulate()
{
    int numTriangles = 0, numVertices = this->_vertices.size();
    while (numTriangles < numVertices - 2)
    {
        continue;
    }
}

float EarClipper::getAngle(Point2D p0, Point2D p1, Point2D p2)
{
    float m1, m2;
    m1 = (p0._y - p1._y) / (p0._x - p1._x);
    m2 = (p2._y - p1._y) / (p2._x - p1._x);

    float theta = std::atan((m1 - m2) / (1 + m1 * m2)) * 180 / M_PI;

    return theta;
}

bool EarClipper::isPointInTriangle(Point2D p0, Point2D p1, Point2D p2)
{
    for (Point2D p : this->_vertices)
    {
        if (p.equals(p0) || p.equals(p1) || p.equals(p2))
        {
            continue;
        }
        // line 0: p0-----p1
        bool line0 = (p1._x - p0._x) * (p._y - p0._y) > (p1._y - p0._y) * (p._x - p0._x);

        // line 1: p1-----p2
        bool line1 = (p2._x - p1._x) * (p._y - p1._y) > (p2._y - p1._y) * (p._x - p1._x);

        // line 2: p2-----p0
        bool line2 = (p0._x - p2._x) * (p._y - p2._y) > (p0._y - p2._y) * (p._x - p2._x);

        if (line0 || line1 || line2)
        {
            return true;
        }
    }
    return false;
}