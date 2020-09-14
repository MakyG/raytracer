#pragma once
#include <math.h>
#include "Vector.h"

class Object{
    virtual void SetCenter(const Vector&) = 0;
    virtual Vector GetCenter() = 0;
    virtual void SetColor(const Vector&) = 0;
    virtual Vector GetColor() = 0;
    virtual void SetNormal(const Vector&) = 0;
    virtual Vector GetNormal() = 0;
    virtual bool Intersects(const Ray& ray) = 0;
};

class Plane : Object{
public:
    // DEFINE PLANE PARAMETERS
    
    Vector center;
	Vector normal;
    Vector color;
    
    // PLANE CONSTRUCTOR
    
	Plane(const Vector& center, const Vector& normal, const Vector& color) : center(center), normal(normal), color(color) {}

private:
	// RETURNS NORMAL OF THE PLANE
	
	inline Vector GetNormal () {
        return normal;
    }
    
    // RETURNS CENTER OF THE PLANE
    
    inline Vector GetCenter(){
        return center;
    }
        
    // CHECKS IF RAY INTERSECTS WITH PLANE
    
    bool Intersects(const Ray& ray) override { 
        // assuming vectors are all normalized
        Vector n = normal;
        Vector p0 = center;
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

class Sphere : Object{
    
    // DEFINE SPHERE VALUES
    
    Vector center;
    double radius;
    Vector color;
    
    // SPHERE CONSTRUCTOR
    
    Sphere(const Vector& center, double radius, const Vector& color) : center(center), radius(radius), color(color) {}

    // RETURNS NORMAL OF THE SPHERE CALCULATED BY ITS CENTER AND RADIUS
    
    inline Vector GetNormal(const Vector& pi) const {
        return Vector(pi - center) / radius;
    }
    
    bool Intersects(const Sphere& sphere) override{
        Vector originToSphere = center - origin;
        double projection = originToSphere.Dot(direction);
        Vector distanceVector = originToSphere - direction * projection;
        double newDistance = distanceVector.Dot(distanceVector);
        double newRadius = radius * radius;
        
        if (newDistance > newRadius)
            return false;
        
        double newLength = projection - sqrt(newRadius - newDistance);
        
        if(newLength < length && newLength > 0){
            length = newLength;
            return true;
        }
        
        return false;
    }
};

class Triangle : Object override{
    
    // DEFINE TRIANGLE PARAMETERS
    
	Vector p0;
    Vector p1;
	Vector p2;
    Vector color;
    
    // TRIANGLE CONSTRUCTOR
    
	Triangle(const Vector& p0, const Vector& p1, const Vector& p2, const Vector& color) : p0(p0), p1(p1), p2(p2), color(color) {}
    
    // RETURNS ORIGIN OF THE TRIANGLE CALCULATED BY ITS THREE POINTS
    
    inline Vector GetOrigin(){
        return (p0 + p1 + p2) / 3;
    }
    
    bool Intersects(const Ray& ray) {    
        Vector v0v1 = p1 - p0; 
        Vector v0v2 = p2 - p0; 
        Vector pvec = ray.direction.CrossProduct(v0v2); 
        double det = v0v1.Dot(pvec); 
        double t, u, v;
        
        // if the determinant is negative the triangle is backfacing
        // if the determinant is close to 0 (kEpsilon), the ray misses the triangle
        if (det < kEpsilon) 
            return false; 
        
        // ray and triangle are parallel if det is close to 0
        if (fabs(det) < kEpsilon) 
            return false; 
        
        double invDet = 1 / det; 
    
        Vector tvec = ray.origin - p0; 
        u = tvec.Dot(pvec) * invDet; 
        if (u < 0 || u > 1) 
            return false; 
    
        Vector qvec = tvec.CrossProduct(v0v1); 
        v = ray.direction.Dot(qvec) * invDet; 
        if (v < 0 || u + v > 1) 
            return false; 
    
        t = v0v2.Dot(qvec) * invDet; 
    
        return true;
    } 
};

