/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#ifndef GL_RAYTRACER_HIT_LIST_H
#define GL_RAYTRACER_HIT_LIST_H

#include "hittable.h"
#include "../materials/LambertianDiffuseMaterial.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    HittableList() = default;

    explicit HittableList(const shared_ptr<hittable>& object) { add(object); }

    void clear() { objects.clear(); }
    void add(const shared_ptr<hittable> &object) { objects.push_back(object); }

    bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override;
};

#endif //GL_RAYTRACER_HIT_LIST_H
