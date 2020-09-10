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
	
	// RETURNS DOT PRODUCT OF TWO VECTORS (SCALAR PRODUCT)
	
    double Dot(const Vector& a, const Vector& b) {
        return (a.x * b.x + a.y * b.y + a.z * b.z);
    }   
    
    // RETURNS PERPENDICULAR VECTOR TO TWO VECTORS
    
    Vector CrossProduct(const Vector& a, const Vector& b){
        Vector finalVector = Vector(0, 0, 0);
        finalVector.x = a.y * b.z - b.y * a.z;
        finalVector.y = b.x * a.z - a.x * b.z;
        finalVector.z = a.x * b.y - b.x * a.y;
        return finalVector;
    }
    
    // CHECKS IF RAY INTERSECTS WITH SPHERE
    
	bool RaySphereIntersection(const Sphere& sphere){
        Vector originToSphere = sphere.center - origin;
        double projection = Dot(originToSphere, direction);
        Vector distanceVector = originToSphere - direction * projection;
        double newDistance = Dot(distanceVector, distanceVector);
        double newRadius = sphere.radius * sphere.radius;
        
        if (newDistance > newRadius)
            return false;
        
        double newLength = projection - sqrt(newRadius - newDistance);
        
        if(newLength < length && newLength > 0){
            length = newLength;
            return true;
        }
        
        return false;
    }
        
    // CHECKS IF RAY INTERSECTS WITH TRIANGLE
    
    bool RayTriangleIntersection(const Triangle& triangle, const Ray& ray) {    
        Vector v0v1 = triangle.p1 - triangle.p0; 
        Vector v0v2 = triangle.p2 - triangle.p0; 
        Vector pvec = CrossProduct(ray.direction, v0v2); 
        double det = Dot(v0v1, pvec); 
        double t, u, v;
        
        // if the determinant is negative the triangle is backfacing
        // if the determinant is close to 0 (kEpsilon), the ray misses the triangle
        if (det < kEpsilon) 
            return false; 
        
        // ray and triangle are parallel if det is close to 0
        if (fabs(det) < kEpsilon) 
            return false; 
        
        double invDet = 1 / det; 
    
        Vector tvec = ray.origin - triangle.p0; 
        u = Dot(tvec, pvec) * invDet; 
        if (u < 0 || u > 1) 
            return false; 
    
        Vector qvec = CrossProduct(tvec, v0v1); 
        v = Dot(ray.direction, qvec) * invDet; 
        if (v < 0 || u + v > 1) 
            return false; 
    
        t = Dot(v0v2, qvec) * invDet; 
    
        return true;
    } 
    
    // CHECKS IF RAY INTERSECTS WITH PLANE
    
    bool RayPlaneIntersection(const Plane& plane, const Ray& ray) { 
        // assuming vectors are all normalized
        Vector n = plane.normal;
        Vector p0 = plane.center;
        Vector l0 = ray.origin;
        Vector l = ray.direction;
        double t;
        double denom = Dot(n, l); 
        if (denom > 1e-6) { 
            Vector p0l0 = p0 - l0; 
            t = Dot(p0l0, n) / denom; 
            return (t >= 0); 
        } 
        
        return false; 
    } 
};
