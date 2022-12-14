//
// Created by Jake on 11/16/2022.
//

#include "Metal.h"

Metal::Metal(const Color &color, double fuzz) {
    this->fuzziness = (fuzz < 1) ? fuzz : 1;
    this->materialColor_ = color;
}

bool Metal::scatter(const Ray &rayIn,
                    const HitRecord &record,
                    Color &attenuation,
                    Ray &scattered) const {
    Vec3 reflected = Vec3::reflect(unitVector(rayIn.direction()), record.normal);
    scattered = Ray(record.p, reflected + fuzziness*randomVectorInUnitSphere());
    attenuation = materialColor_;
    return (dot(scattered.direction(), record.normal) > 0);
}

Color Metal::materialColor() {
    return materialColor_;
}
