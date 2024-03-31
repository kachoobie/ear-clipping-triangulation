#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Point2D.hpp"

class FileReader
{
private:
    std::string _filePath;

public:
    FileReader(std::string filePath);
    ~FileReader();
    std::vector<Point2D> extractPoints();
};