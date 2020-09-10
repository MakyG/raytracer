#include <fstream>
#include <cmath>
#include "Vector.h"
#include "Ray.h"
#include "Sphere.h"
#include "Light.h"
#include "Plane.h"
#include "Triangle.h"

// CLAMP VALUE TO MIN IF VALUE IS SMALLER THAN MIN, MAX IF VALUE IS BIGGER THAN MAX
// SINGLE VECTOR CLAMP 255

void clamp255(Vector& col) {
  col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
  col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
  col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

// SINGLE VALUE CLAMP

double basicClamp(double& value, double min, double max) {
  return value = (value > max) ? max : (value < min) ? min : value;
}

int main() {
    
    // SET CANVAS HEIGHT AND WIDTH
    
	const int height = 500;
	const int width = 500;

	// PREDEFINE COLORS
	
    Vector white(255, 255, 255);
    Vector grey(100, 100, 100);
    Vector black(0, 0, 0);
    Vector red(255, 0, 0);
    Vector green(0, 255, 0);
    Vector blue(0, 0, 255);
    Vector lightBlue(190, 190, 255);
    Vector yellow(255, 255, 0);

    // CREATE RENDERER FILE
    
	std::ofstream out("output.bmp");
	out << "P3\n" << width << "\n" << height << "\n" << "255\n";
    
    // CREATES PIXEL FILL
    
    Vector pix_col(black);
    
    // PREPARE SCENE OBJECTS
    
    Sphere sphere(Vector(2, 0, 10), 5, blue);
    Plane plane(Vector(2, 0, 0), Vector(0, -1, 0), grey);
    Triangle triangle(Vector(-0.5, 0, 1), Vector(-2, 1.8, 2), Vector(2, 1, 2.3), red);
    Light light = Light(Vector(-7, 2, 4), white);
    
    // SET UP CAMERA
    
    Vector cameraPosition = Vector(0, 0, 0);
    Vector viewDirection = Vector(0, 0, 1);
    double screenDistance = 1;
    
    // DEFINE SCREEN CENTER
    
    Vector screenCenter = cameraPosition + viewDirection * screenDistance;
    Vector p0 = screenCenter + Vector(-1, 1, 0);
    Vector p1 = screenCenter + Vector(1, 1, 0);
    Vector p2 = screenCenter + Vector(-1, -1, 0);

    // RENDERING LOOP
    
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
            
            double t;
            pix_col = lightBlue;
            
            double u = (double)x / width;
            double v = (double)y / height;

            Vector hitPoint = p0 + (p1 - p0) * u + (p2 - p0) * v; // Point of intersection
            Vector rayDirection = hitPoint - cameraPosition;
            
            // CREATE RAY
            
            Ray ray = Ray(cameraPosition, rayDirection, 1000000);
            
            // SPHERE COLOR CALCULATION
            
            if (ray.RaySphereIntersection(sphere) == true) {
				Vector hitPoint = ray.origin + ray.direction * ray.length;
				Vector L = light.center - hitPoint;
				Vector N = sphere.getNormal(hitPoint);
 				double dt = ray.Dot(L.normalize(), N.normalize());
                
				pix_col = (sphere.color + light.color * dt);
				clamp255(pix_col);
			}
			
			// TRIANGLE COLOR CALCULATION
			
			else if (ray.RayTriangleIntersection(triangle, ray) == true) {
                double global_light_intensity = 0;
                Vector obj_color = triangle.color;
                pix_col = Vector(obj_color.x * global_light_intensity, obj_color.y * global_light_intensity, obj_color.z * global_light_intensity);
                
                Vector diffuse_light_normal = (hitPoint + triangle.getNormal() * 1e-3);
                Vector light_direction = (light.center - hitPoint).normalize();
                
                double dotProduct = ray.Dot(diffuse_light_normal, light_direction);
				double light_strength = basicClamp(dotProduct, 0, 1);
                Vector multiplicator = Vector(light.color.x / 255, light.color.y / 255, light.color.z / 255) * light_strength;
                Vector object_color = triangle.color;
                Vector add_color = Vector(object_color.x * multiplicator.x, object_color.y * multiplicator.y, object_color.z * multiplicator.z);
                pix_col = pix_col + add_color;
            }
            
            // PLANE COLOR CALCULATION
			
			else if (ray.RayPlaneIntersection(plane, ray) == true) {
 				double global_light_intensity = 0.25;
                Vector obj_color = plane.color;
                pix_col = Vector(obj_color.x * global_light_intensity, obj_color.y * global_light_intensity, obj_color.z * global_light_intensity);
                
                Vector diffuse_light_normal = (hitPoint + plane.getNormal()).normalize();
                Vector light_direction = (light.center - hitPoint).normalize();
                
                double dotProduct = ray.Dot(diffuse_light_normal, light_direction);
				double light_strength = basicClamp(dotProduct, 0, 1);
                Vector multiplicator = Vector(light.color.x / 255, light.color.y / 255, light.color.z / 255) * light_strength;
                Vector object_color = plane.color;
                Vector add_color = Vector(object_color.x * multiplicator.x, object_color.y * multiplicator.y, object_color.z * multiplicator.z);
                pix_col = pix_col + add_color;
			}
			
			// RENDER TO FILE PIXEL BY PIXEL
			
			out << (int)pix_col.x << ' ' << (int)pix_col.y << ' ' << (int)pix_col.z << '\n';
		}
	}
}
