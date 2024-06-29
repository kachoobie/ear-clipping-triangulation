#include "Triangle.hpp"

Triangle::Triangle(Point2D p1, Point2D p2, Point2D p3)
{
    if (p1.equals(p2) || p1.equals(p3) || p2.equals(p3))
    {
        exit(EXIT_FAILURE);
    }
    this->_p1 = p1;
    this->_p2 = p2;
    this->_p3 = p3;
}

Triangle::Triangle()
{
}

Triangle::~Triangle()
{
}

bool Triangle::equals(Triangle other)
{
    return (this->_p1.equals(other._p1) && this->_p2.equals(other._p2) && this->_p3.equals(other._p3)) || (this->_p2.equals(other._p1) && this->_p3.equals(other._p2) && this->_p1.equals(other._p3)) || (this->_p3.equals(other._p1) && this->_p1.equals(other._p2) && this->_p2.equals(other._p3));
}