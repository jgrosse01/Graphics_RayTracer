//
// Created by jgros on 12/12/2022.
//

#ifndef GL_RAYTRACER_DIFFUSELIGHT_H
#define GL_RAYTRACER_DIFFUSELIGHT_H

#include <memory>
#include "MaterialInterface.h"
#include "../rt_lib/RandomUtilites.h"
#include "../textures/TextureInterface.h"
#include "../textures/SolidColor.h"

using std::shared_ptr;
using std::make_shared;


class DiffuseLight : public MaterialInterface{
private:
    shared_ptr<TextureInterface> emit_;

public:
    DiffuseLight(shared_ptr<TextureInterface> a);
    DiffuseLight(Color color);

    virtual bool scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const override;

    virtual Color emitted(double u, double v, const Point3& p) const override;
};


#endif //GL_RAYTRACER_DIFFUSELIGHT_H
