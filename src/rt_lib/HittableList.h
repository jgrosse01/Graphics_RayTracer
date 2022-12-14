/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#ifndef GL_RAYTRACER_HIT_LIST_H
#define GL_RAYTRACER_HIT_LIST_H

#include "HittableInterface.h"
#include "../materials/LambertianDiffuseMaterial.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public HittableInterface {
public:
    std::vector<shared_ptr<HittableInterface>> objects_;

    HittableList() = default;

    explicit HittableList(const shared_ptr<HittableInterface>& object) { add(object); }

    void clear() { objects_.clear(); }
    void add(const shared_ptr<HittableInterface> &object) { objects_.push_back(object); }

    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;
};

#endif //GL_RAYTRACER_HIT_LIST_H
