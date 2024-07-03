#include "EarClipper.hpp"

EarClipper::EarClipper(std::vector<Point2D> vertices)
{
    this->_vertices = vertices;
}

EarClipper::~EarClipper()
{
}

std::vector<Triangle> EarClipper::triangulate()
{
    std::vector<Triangle> triangles;
    std::vector<Point2D> verticesClone = this->_vertices;
    int numVertices = this->_vertices.size();
    while (triangles.size() < numVertices - 2)
    {
        for (int i = 2; i < verticesClone.size(); ++i)
        {
            Point2D p0 = verticesClone.at(i - 2), p1 = verticesClone.at(i - 1), p2 = verticesClone.at(i);

            if (!isPointInTriangle(p0, p1, p2) && getAngle(p0, p1, p2) < 180)
            {
                triangles.push_back(Triangle(p0, p1, p2));
                verticesClone.erase(verticesClone.begin() + i - 1);
            }
        }

        if (verticesClone.size() == 3)
        {
            triangles.push_back(Triangle(verticesClone[0], verticesClone[1], verticesClone[2]));
        }
    }

    return triangles;
}

float EarClipper::getAngle(Point2D p0, Point2D p1, Point2D p2)
{
    float m1, m2;
    m1 = p0._x - p1._x == 0 ? 1.0 : (float)(p0._y - p1._y) / (float)(p0._x - p1._x);
    m2 = p2._x - p1._x == 0 ? 1.0 : (float)(p2._y - p1._y) / (float)(p2._x - p1._x);;

    float theta = std::atan((m1 - m2) / (1 + m1 * m2)) * 180 / M_PI;

    return std::abs(theta);
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

        if (line0 && line1 && line2)
        {
            return true;
        }
    }
    return false;
}