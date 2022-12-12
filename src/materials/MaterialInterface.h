//
// Created by Jake on 11/16/2022.
//

#ifndef GL_RAYTRACER_MATERIALINTERFACE_H
#define GL_RAYTRACER_MATERIALINTERFACE_H

#include "../rt_lib/Ray.h"

struct HitRecord;

class MaterialInterface {
public:
    virtual bool scatter(
            const Ray &rayIn, const HitRecord &record, Color &attenuation, Ray &scattered
            ) const = 0;
};

#endif //GL_RAYTRACER_MATERIALINTERFACE_H
