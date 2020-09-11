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
	std::vector<Triangle> triangles;
	std::vector<Plane> planes;
	std::vector<Sphere> spheres;
    std::vector<Triangle> GetTriangles();
    std::vector<Plane> GetPlanes();
    std::vector<Sphere> GetSpheres();
private:
	void Render();
 	void RenderObjects();
 	void AddObject();
    void AddTriangle();
    void AddPlane();
    void AddSphere();
};
