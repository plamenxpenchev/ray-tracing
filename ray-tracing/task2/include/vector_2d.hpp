#pragma once

#include <cmath>
#include <iostream>
#include <vector>

using std::sqrt;
using std::vector;

class Vector2D {
private:
	vector<int> v;
public:
	Vector2D() : v{ 0,0 } {}
	Vector2D(int vx, int vy) : v{ vx, vy } {}

	int x() const;
	int y() const;

	int operator[](int i) const;
	int& operator[](int i);
};

inline std::ostream& operator<<(std::ostream& out, const Vector2D& v) {

	return out << v.x() << ' ' << v.y();
}