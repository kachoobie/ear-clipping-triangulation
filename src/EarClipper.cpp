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

}

float EarClipper::getAngle(Point2D shared, Point2D p1, Point2D p2)
{
    float m1, m2;

    m1 = (p1._y - shared._y) / (p1._x - shared._x);
    m2 = (p2._y - shared._y) / (p2._x - shared._x);

    float theta = std::atan((m1 - m2) / (1 + m1 * m2)) * 180 / M_PI;

    return theta;
}