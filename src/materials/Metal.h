//
// Created by Jake on 11/16/2022.
//

#ifndef GL_RAYTRACER_METAL_H
#define GL_RAYTRACER_METAL_H

#include "MaterialInterface.h"
#include "../rt_lib/RandomUtilites.h"
#include "../rt_lib/Hittable.h"
#include "../rt_lib/Vec3.h"

class Metal : public MaterialInterface{
private:
    Color materialColor_;
    double fuzziness;
public:
    explicit Metal(const Color &color, double fuzz);

    bool scatter(
            const Ray &rayIn, const HitRecord &record, Color &attenuation, Ray &scattered
            ) const override;

    Color materialColor();
};


#endif //GL_RAYTRACER_METAL_H
