//
// Created by jgros on 12/14/2022.
//

#ifndef GL_RAYTRACER_TRANSLATE_H
#define GL_RAYTRACER_TRANSLATE_H

#include <memory>
#include "../rt_lib/Hittable.h"

class Translate : public Hittable {
private:
    shared_ptr<Hittable> obj_;
    Vec3 offset_;
public:
    Translate(shared_ptr<Hittable> obj, const Vec3& displacement);

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& record) const override;
};


#endif //GL_RAYTRACER_TRANSLATE_H
