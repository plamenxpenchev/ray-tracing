#include "ray.hpp"

Point3D Ray::getOrigin() const {
	return origin;
}

Vector3D Ray::getDirection() const {
	return direction;
}