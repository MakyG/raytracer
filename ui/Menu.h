#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "./raytracer/Triangle.h"
#include "./raytracer/Plane.h"
#include "./raytracer/Sphere.h"
#include "./raytracer/Vector.h"
#include "./raytracer/Raytracer.h"

class Menu {
public:
	void MainMenu();
    Vector center = Vector(0, 0, 0);
    Vector color = Vector(0, 0, 0);
    Vector normal = Vector(0, 0, 0);
    double radius = 0;
    Vector p0 = Vector(0, 0, 0);
    Vector p1 = Vector(0, 0, 0);
    Vector p2 = Vector(0, 0, 0);
private:
	void Render();
 	void RenderObjects();
 	void AddObject();
    void AddTriangle();
    void AddPlane();
    void AddSphere();
    Raytracer tracer;
};
