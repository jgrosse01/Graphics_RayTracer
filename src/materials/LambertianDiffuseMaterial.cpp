//
// Created by Jake on 11/16/2022.
//

#include "LambertianDiffuseMaterial.h"

LambertianDiffuseMaterial::LambertianDiffuseMaterial(const Color &color) {
    this->materialColor_ = color;
}

bool LambertianDiffuseMaterial::scatter(const Ray &rayIn, const hit_record &record, Color &attenuation,
                                        Ray &scattered) const {
    auto scatterDirection = record.normal + randomUnitVector();
    if (scatterDirection.nearZero())
        scatterDirection = record.normal;
    scattered = Ray(record.p, scatterDirection);
    attenuation = materialColor_;
    return true;
}
