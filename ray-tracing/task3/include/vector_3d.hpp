#pragma once

#include <cmath>
#include <iostream>
#include <vector>

#include "fast_inverse_sqrt.hpp"

using std::sqrt;
using std::vector;

class Vector3D {
private:
	vector<float> v;
public:
	Vector3D() : v{ 0.0f, 0.0f, 0.0f } {}
	Vector3D(float vx, float vy, float vz) : v{ vx, vy, vz } {}

	float x() const;
	float y() const;
	float z() const;

	Vector3D& normalize();
	float lengthSquared() const;

	Vector3D& operator*=(const float num);

	float operator[](int i) const;
	float& operator[](int i);
};

inline std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
	return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

// Type aliases
using Point3D = Vector3D;
using Color = Vector3D;