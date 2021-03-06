#pragma once

struct Vector{
    
    // DEFINE VECTOR PARAMETERS
    
    double x,y,z;
    
    // VECTOR CONSTRUCTOR
    
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}
    
    // OPERATIONS BETWEEN VECTORS OR VALUES
    
    Vector operator + (const Vector& v) const {
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	Vector operator - (const Vector& v) const {
		return Vector(x - v.x, y - v.y, z - v.z);
	}
    Vector operator * (double d) const {
		return Vector(x * d, y * d, z * d);
	}
	Vector operator * (const Vector& v) const { 
        return Vector(x * v.x, y * v.y, z * v.z); 
    }
    Vector operator / (double d) const {
		return Vector(x / d, y / d, z / d);
	}
	Vector operator / (const Vector& v) const {
        return Vector(x / v.x, y / v.y, z / v.z); 
    }	
    
    // RETURNS DATA TO ITS NORMAL CONDITION
    
	Vector normalize() const {
        double magnitude = sqrt(x * x + y * y + z * z);
        return Vector(x / magnitude, y / magnitude, z / magnitude);
    }
    
    // RETURNS CROSS PRODUCT OF TWO VECTORS
    
    inline Vector CrossProduct(const Vector& b){
        Vector finalVector = Vector(0, 0, 0);
        finalVector.x = y * b.z - b.y * z;
        finalVector.y = b.x * z - x * b.z;
        finalVector.z = x * b.y - b.x * y;
        return finalVector;
    }
    
    // RETURNS NORMAL OF THE TRIANGLE
	
    inline Vector GetNormal () {
        Vector normal = Vector(0, 0, 0);
        Vector A = p1 - p0; // Edge Vectors A, B
        Vector B = p2 - p0;
        normal = CrossProduct(A, B).normalize();
        return normal;
    }
    
	// RETURNS DOT PRODUCT OF TWO VECTORS (SCALAR PRODUCT)
	
    double Dot(const Vector& b) {
        return (x * b.x + y * b.y + z * b.z);
    }
};
