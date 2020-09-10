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
};
