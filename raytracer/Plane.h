#pragma once
#include <math.h>
#include "Vector.h"

struct Plane {
    
    // DEFINE PLANE PARAMETERS
    
    Vector center;
	Vector normal;
    Vector color;
    
    // PLANE CONSTRUCTOR
    
	Plane(const Vector& center, const Vector& normal, const Vector& color) : center(center), normal(normal), color(color) {}
	
	// RETURNS NORMAL OF THE PLANE
	
	Vector getNormal () {
        return normal;
    }
    
    // RETURNS CENTER OF THE PLANE
    
    Vector getCenter(){
        return center;
    }
};
