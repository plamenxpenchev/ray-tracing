#pragma once

#include "vector_3d.hpp"

class Ray {
private:
	Point3D origin;
	Vector3D direction;
public:
	Ray() {}
	Ray(const Point3D& o, const Vector3D& d) : origin{o}, direction{d} {}

	Point3D getOrigin() const;
	Vector3D getDirection() const;
};