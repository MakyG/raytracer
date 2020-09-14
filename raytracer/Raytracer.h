#pragma once
#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>

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
    Object& GetObject(int i);
    inline void AddTriangle(const Vector& p0, const Vector& p1, const Vector& p2, const Vector& color){
        objects.push_back(std::make_shared<Triangle>(p0, p1, p2, color));
    }
    inline void AddPlane(const Vector& center, const Vector& normal, const Vector& color){
        objects.push_back(std::make_shared<Plane>(center, normal, color));
    }
    inline void AddSphere(const Vector& center, double radius, const Vector& color){
        objects.push_back(std::make_shared<Sphere>(center, radius, color));
    }
    
  std::vector<std::shared_ptr<Object>> objects;
};

