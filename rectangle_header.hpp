#include <iostream>
#include <vector>
#include "shapes.hpp"

class rectangle : public Shape
{
    int width;
    int height;

public: 
    rectangle(int posx, int posy, int w, int h, int col = 230) : width(w), height(h), Shape(posx, posy, col) {}
    float area() const {return width*height;}
} ;

