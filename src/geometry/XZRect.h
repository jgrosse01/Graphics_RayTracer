//
// Created by jgros on 12/12/2022.
//

#ifndef GL_RAYTRACER_XZRECT_H
#define GL_RAYTRACER_XZRECT_H

#include <memory>
#include "../rt_lib/Hittable.h"
#include "../materials/MaterialInterface.h"

class XZRect : public Hittable {
private:
    shared_ptr<MaterialInterface> materialPointer_;
    double x0, x1, z0, z1, k;
public:
    XZRect() {};
    XZRect(double x0, double x1, double z0, double z1, double k, shared_ptr<MaterialInterface> material);

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& record) const override;
};


#endif //GL_RAYTRACER_XZRECT_H
