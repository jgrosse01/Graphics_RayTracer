/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#ifndef GL_RAYTRACER_RAY_H
#define GL_RAYTRACER_RAY_H

#include <cmath>
#include "vec3.h"

class Ray {
private:
    point3 orig;
    vec3 dir;
public:
    Ray(const point3& origin, const vec3& direction);

    point3 origin() const;
    vec3 direction() const;

    point3 at(double t) const;
};

#endif //GL_RAYTRACER_RAY_H
