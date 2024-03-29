#include <stdio.h>
#include <iostream>
#include "FileReader.hpp"

int main()
{

    FileReader fr("./shape_files/s1.txt");
    
    fr.extractPoints();
}