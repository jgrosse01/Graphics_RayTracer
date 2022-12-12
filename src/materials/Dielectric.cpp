//
// Created by jgros on 12/11/2022.
//

#include "Dielectric.h"

Dielectric::Dielectric(double indexOfRefraction, const Color& color) {
    this->ir = indexOfRefraction;
    this->color = color;
}

bool Dielectric::scatter(const Ray& rayIn, const hit_record& record, Color& attenuation, Ray& scattered) const {
    attenuation = this->color;
    double refractionRatio = record.front_face ? (1.0/ir) : ir;
    Vec3 unitDir = unitVector(rayIn.direction());

    double cosTheta = fmin(dot(-unitDir, record.normal), 1.0);
    double sinTheta = sqrt(1.0 - cosTheta*cosTheta);

    Vec3 dir;

    // if can refract
    if (refractionRatio * sinTheta > 1.0 || reflectance(cosTheta, refractionRatio) > randomDouble()) {
        dir = Vec3::reflect(unitDir, record.normal);
    } else {
        dir = Vec3::refract(unitDir, record.normal, refractionRatio);
    }

    scattered = Ray(record.p, dir);
    return true;
}

double Dielectric::reflectance(double cosine, double reflectanceIndex) {
    // Schlick's Reflectance
    auto r = (1-reflectanceIndex) / (1+reflectanceIndex);
    r = r*r;
    return r + (1-r)*pow((1-cosine),5);
}