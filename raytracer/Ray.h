#pragma once
#include "Vector.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"

constexpr double kEpsilon = 1e-8;

struct Ray{
    
    // DEFINE RAY PARAMETERS
    
	Vector origin;
	Vector direction;
    double length;
    
    // RAY CONSTRUCTOR
    
	Ray(const Vector& origin, const Vector& direction, double length) : origin(origin), direction(direction), length(length){}
};
