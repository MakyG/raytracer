#pragma once
#include <math.h>
#include "Vector.h"
#include "Ray.h"

struct Triangle {
    
    // DEFINE TRIANGLE PARAMETERS
    
	Vector p0;
    Vector p1;
	Vector p2;
    Vector color;
    
    // TRIANGLE CONSTRUCTOR
    
	Triangle(const Vector& p0, const Vector& p1, const Vector& p2, const Vector& color) : p0(p0), p1(p1), p2(p2), color(color) {}
	
	// RETURNS NORMAL OF THE TRIANGLE
	
    Vector getNormal () {
        Vector normal = Vector(0, 0, 0);
        Vector A = p1 - p0; // Edge Vectors A, B
        Vector B = p2 - p0;
        normal = CrossProduct(A, B).normalize();
        return normal;
    }
    
    // RETURNS CROSS PRODUCT OF TWO VECTORS
    
    Vector CrossProduct(const Vector& a, const Vector& b){
        Vector finalVector = Vector(0, 0, 0);
        finalVector.x = a.y * b.z - b.y * a.z;
        finalVector.y = b.x * a.z - a.x * b.z;
        finalVector.z = a.x * b.y - b.x * a.y;
        return finalVector;
    }
    
    // RETURNS ORIGIN OF THE TRIANGLE CALCULATED BY ITS THREE POINTS
    
    Vector getOrigin(){
        return (p0 + p1 + p2) / 3;
    }
};

