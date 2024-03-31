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
    return 1.1f;
}