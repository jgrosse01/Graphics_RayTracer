//
// Created by Jake on 11/16/2022.
//

#include "Metal.h"

Metal::Metal(const Color &color) {
    this->materialColor_ = color;
}

bool Metal::scatter(const Ray &rayIn,
                    const hit_record &record,
                    Color &attenuation,
                    Ray &scattered) const {
    Vec3 reflected = Vec3::reflect(unitVector(rayIn.direction()), record.normal);
    scattered = Ray(record.p, reflected);
    attenuation = materialColor_;
    return (dot(scattered.direction(), record.normal) > 0);
}

Color Metal::materialColor() {
    return materialColor_;
}
