#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileReader
{
private:
    std::string _filePath;

public:
    FileReader(std::string filePath);
    ~FileReader();
    std::vector<float> extractPoints();
};