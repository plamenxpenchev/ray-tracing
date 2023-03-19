#include "vector_3d.hpp"

float Vector3D::x() const {
	return v[0];
}

float Vector3D::y() const {
	return v[1];
}

float Vector3D::z() const {
	return v[2];
}

Vector3D& Vector3D::normalize() {
	return *this *= fastInverseSqrt(lengthSquared());
}

float Vector3D::lengthSquared() const {
	return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
};

Vector3D& Vector3D::operator*=(const float num) {
	v[0] *= num;
	v[1] *= num;
	v[2] *= num;

	return *this;
}

float Vector3D::operator[](int i) const {
	return v[i];
}

float& Vector3D::operator[](int i) {
	return v[i];
}