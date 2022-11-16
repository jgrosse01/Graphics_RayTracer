//
// Created by Jake on 11/16/2022.
//

#include "RandomUtilites.h"

double randomDouble() {
    return s_distribution(s_generator);
}

double randomDouble(double min, double max) {
    return min + (max-min)*randomDouble();
}

Vec3 randomVector() {
    return {randomDouble(), randomDouble(), randomDouble()};
}

Vec3 randomVector(double min, double max) {
    return {randomDouble(min, max), randomDouble(min, max), randomDouble(min, max)};
}

Vec3 randomVectorInUnitSphere() {
    for(;;) {
        auto p = randomVector(-1,1);
        if (p.lengthSquared() > 1) continue;
        return p;
    }
}

Vec3 randomUnitVector() {
    return unitVector(randomVectorInUnitSphere());
}

Vec3 randomVectorInHemisphere(const Vec3 &normalVector) {
    Vec3 inUnitSphere = randomVectorInUnitSphere();
    if (dot(inUnitSphere, normalVector) > 0.0) {
        return inUnitSphere;
    }
    return -inUnitSphere;
}