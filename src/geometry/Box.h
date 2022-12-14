//
// Created by jgros on 12/14/2022.
//

#ifndef GL_RAYTRACER_BOX_H
#define GL_RAYTRACER_BOX_H

#include <memory>
#include "../rt_lib/Hittable.h"
#include "../rt_lib/HittableList.h"
#include "../materials/MaterialInterface.h"
#include "../geometry/XYRect.h"
#include "../geometry/YZRect.h"
#include "../geometry/XZRect.h"


class Box : public Hittable {
private:
    Point3 boxMin_;
    Point3 boxMax_;
    HittableList sides_;

public:
    Box() {};
    Box(const Vec3& p0, const Vec3& p1, shared_ptr<MaterialInterface> material);

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& record) const override;
};


#endif //GL_RAYTRACER_BOX_H
