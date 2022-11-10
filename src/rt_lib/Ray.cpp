/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#include "Ray.h"

Ray::Ray(const point3 &origin, const vec3 &direction) {
    this->orig = origin;
    this->dir = direction;
}

point3 Ray::origin() const {
    return this->orig;
}

vec3 Ray::direction() const {
    return this->dir;
}

point3 Ray::at(double t) const {
    return orig + t*dir;
}
