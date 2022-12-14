//
// Created by jgros on 12/12/2022.
//

#ifndef GL_RAYTRACER_RECTANGLE_H
#define GL_RAYTRACER_RECTANGLE_H

#include <memory>
#include "../rt_lib/Hittable.h"
#include "../materials/MaterialInterface.h"

using std::shared_ptr;

class Rectangle : public Hittable{
private:
    shared_ptr<MaterialInterface> materialPointer_;
    double x0, x1, y0, y1, k;
public:
    Rectangle() {};
    Rectangle(double x0, double x1, double y0, double y1, double k, shared_ptr<MaterialInterface> material);

    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& record) const override;
};


#endif //GL_RAYTRACER_RECTANGLE_H
