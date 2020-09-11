#pragma once
#include "Vector.h"

struct Light{
    
    // DEFINE LIGHT PARAMETERS
    
    Vector center;
    Vector color;
    
    // LIGHT CONSTRUCTOR
    
    Light (Vector center, Vector color) : center(center), color(color){}
};
