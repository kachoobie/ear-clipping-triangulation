#include <stdio.h>
#include <iostream>
#include <vector>

#include "FileReader.hpp"

int main()
{

    FileReader fr("./shape_files/s1.txt");
    
    std::vector<Point2D> points = fr.extractPoints();
    for (Point2D p : points)
    {
        std::cout << p._x << " " << p._y << std::endl;
    }
}