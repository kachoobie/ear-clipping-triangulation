#include "Point2D.hpp"

Point2D::Point2D(float x, float y)
{
    this->_x = x;
    this->_y = y;
}

Point2D::~Point2D()
{
}

bool Point2D::equals(Point2D p)
{
    float delta = 0.00001;
    return std::abs(this->_x - p._x < delta) && std::abs(this->_y - p._y < delta);
}