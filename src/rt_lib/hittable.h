/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#ifndef GL_RAYTRACER_HITTABLE_H
#define GL_RAYTRACER_HITTABLE_H

#include <memory>
#include "Ray.h"
#include "../materials/MaterialInterface.h"

using std::shared_ptr;

struct hit_record {
    shared_ptr<MaterialInterface> materialPointer;

    Point3 p;
    Vec3 normal;
    double t;
    double u;
    double v;
    bool front_face;

    void set_face_normal(const Ray &r, const Vec3 &outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif //GL_RAYTRACER_HITTABLE_H
