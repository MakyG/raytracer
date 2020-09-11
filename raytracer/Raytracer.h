#pragma once
#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>

#include "../Menu.h"
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Light.h"
#include "Plane.h"
#include "Triangle.h"



class Raytracer{
public:
    void clamp255(Vector& col);
    double basicClamp(double& value, double min, double max);
    void Render();
    
//  std::vector<Triangle> triangles;
// 	std::vector<Plane> planes;
// 	std::vector<Sphere> spheres;
};

