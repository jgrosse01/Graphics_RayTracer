//
// Created by jgros on 12/11/2022.
//

#ifndef GL_RAYTRACER_DIELECTRICS_H
#define GL_RAYTRACER_DIELECTRICS_H

#include "MaterialInterface.h"
#include "../rt_lib/Hittable.h"
#include "../rt_lib/RandomUtilites.h"


class Dielectric : public MaterialInterface {
private:
    double ir;
    Color color;

    static double reflectance(double cosine, double reflectanceIndex);

public:
    explicit Dielectric(double indexOfRefraction, const Color& color);

    bool scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& Scattered) const override;
};


#endif //GL_RAYTRACER_DIELECTRICS_H
