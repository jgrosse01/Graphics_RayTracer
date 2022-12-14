//
// Created by jgros on 12/14/2022.
//

#ifndef GL_RAYTRACER_ROTATEY_H
#define GL_RAYTRACER_ROTATEY_H

#include <memory>
#include "../rt_lib/HittableInterface.h"
#include "../rt_lib/RandomUtilites.h"

class RotateY : public HittableInterface {
private:
    shared_ptr<HittableInterface> obj_;
    double sinTheta_;
    double cosTheta_;

public:
    RotateY(shared_ptr<HittableInterface> obj, double angle);

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& record) const override;
};


#endif //GL_RAYTRACER_ROTATEY_H
