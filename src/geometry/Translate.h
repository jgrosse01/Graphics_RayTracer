//
// Created by jgros on 12/14/2022.
//

#ifndef GL_RAYTRACER_TRANSLATE_H
#define GL_RAYTRACER_TRANSLATE_H

#include <memory>
#include "../rt_lib/HittableInterface.h"

class Translate : public HittableInterface {
private:
    shared_ptr<HittableInterface> obj_;
    Vec3 offset_;
public:
    Translate(shared_ptr<HittableInterface> obj, const Vec3& displacement);

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& record) const override;
};


#endif //GL_RAYTRACER_TRANSLATE_H
