//
// Code modified from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
//

#ifndef GL_RAYTRACER_SPHERE_H
#define GL_RAYTRACER_SPHERE_H

#include "../rt_lib/hittable.h"

class Sphere : public hittable {
public:
    Point3 center;
    double radius;
    Color color;

    Sphere(Point3 center, double radius);

    bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;
};


#endif //GL_RAYTRACER_SPHERE_H
