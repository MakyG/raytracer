#pragma once
#include <math.h>
#include "Vector.h"

struct Sphere{
    
    // DEFINE SPHERE VALUES
    
    Vector center;
    double radius;
    Vector color;
    
    // SPHERE CONSTRUCTOR
    
    Sphere(const Vector& center, double radius, const Vector& color) : center(center), radius(radius), color(color) {}

    // RETURNS NORMAL OF THE SPHERE CALCULATED BY ITS CENTER AND RADIUS
    
    Vector getNormal(const Vector& pi) const {
        return Vector(pi - center) / radius;
    }
};
