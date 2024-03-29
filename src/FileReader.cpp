#include "FileReader.hpp"

FileReader::FileReader(std::string filePath)
{
    this->_filePath = filePath;
}

FileReader::~FileReader()
{
}

std::vector<float> FileReader::extractPoints()
{
    std::ifstream f(this->_filePath);
    std::string line;

    while(getline(f, line))
    {
        std::cout << line << std::endl;
    }

    std::vector<float> points;

    return points;
}
