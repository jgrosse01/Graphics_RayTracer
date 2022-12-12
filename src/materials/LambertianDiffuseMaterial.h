//
// Created by Jake on 11/16/2022.
//

#ifndef GL_RAYTRACER_LAMBERTIANDIFFUSEMATERIAL_H
#define GL_RAYTRACER_LAMBERTIANDIFFUSEMATERIAL_H

#include "MaterialInterface.h"
#include "../rt_lib/Hittable.h"
#include "../rt_lib/RandomUtilites.h"

class LambertianDiffuseMaterial : public MaterialInterface{
private:
    Color materialColor_;
public:
    explicit LambertianDiffuseMaterial(const Color &color);

    bool scatter(
            const Ray &rayIn, const HitRecord &record, Color &attenuation, Ray &scattered
            ) const override;

    Color materialColor();
};


#endif //GL_RAYTRACER_LAMBERTIANDIFFUSEMATERIAL_H
