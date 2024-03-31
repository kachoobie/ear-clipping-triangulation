#include "FileReader.hpp"

FileReader::FileReader(std::string filePath)
{
    this->_filePath = filePath;
}

FileReader::~FileReader()
{
}

std::vector<Point2D> FileReader::extractPoints()
{
    std::vector<Point2D> points;

    std::ifstream f(this->_filePath);
    std::string line;

    while(getline(f, line))
    {
        
        std::stringstream s(line);
        float x, y;
        std::string word;
        int numWords = 0;
        while (s >> word)
        {
            if (numWords == 0)
            {
                x = std::stof(word);
            }
            else if (numWords == 1)
            {
                y = std::stof(word);
            }
            ++numWords;
        }

        Point2D p(x, y);
        points.emplace_back(p);
    }

    return points;
}
