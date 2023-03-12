#pragma once

#include "vector_2d.hpp"
#include "ratio.hpp"

bool in_earth(Vector2D point);
bool in_sun(Vector2D point);
bool in_planetary_ellipse(Vector2D point);