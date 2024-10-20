#ifndef MAP_H
#define MAP_H
#include <array>
#include <string>
#include <iostream>

using namespace std;

class Map{
private:
    char** array;

public:
    Map();
    ~Map();

    void CreateMap();

    void DisplayMap();


};
#endif