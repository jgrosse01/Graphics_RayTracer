/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#ifndef GL_RAYTRACER_RAY_H
#define GL_RAYTRACER_RAY_H

#include <cmath>
#include "Vec3.h"

class Ray {
private:
    Point3 origin_;
    Vec3 direction_;
public:
    Ray();
    Ray(const Point3& origin, const Vec3& direction);

    Point3 origin() const;
    Vec3 direction() const;

    Point3 at(double t) const;
};

#endif //GL_RAYTRACER_RAY_H
