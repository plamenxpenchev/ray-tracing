#include "vector_2d.hpp"

int Vector2D::x() const {

	return v[0];
}

int Vector2D::y() const {

	return v[1];
}

int Vector2D::operator[](int i) const {

	return v[i];
}

int& Vector2D::operator[](int i) {

	return v[i];
}