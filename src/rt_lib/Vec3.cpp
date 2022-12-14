/*
 * Vec3 is a simple implementation of a three-dimensional vector.
 * Author: Jacob Grosse (10 November, 2022)
 */

#include "Vec3.h"

Vec3::Vec3() {
    this->coordinates_[0] = 0;
    this->coordinates_[1] = 0;
    this->coordinates_[2] = 0;
}

Vec3::Vec3(double x, double y, double z) {
    this->coordinates_[0] = x;
    this->coordinates_[1] = y;
    this->coordinates_[2] = z;
}

double Vec3::x() {
    return this->coordinates_[0];
}
double Vec3::y() {
    return this->coordinates_[1];
}
double Vec3::z() {
    return this->coordinates_[2];
}

void Vec3::setX(float x) {
    this->coordinates_[0] = x;
}

void Vec3::setY(float y) {
    this->coordinates_[1] = y;
}

void Vec3::setZ(float z) {
    this->coordinates_[2] = z;
}

Vec3 Vec3::operator-() const {
    return {-coordinates_[0], -coordinates_[1], -coordinates_[2]};
}

double Vec3::operator[](int i) const {
    return coordinates_[i];
}

Vec3& Vec3::operator+=(const Vec3 &v) {
    coordinates_[0] += v.coordinates_[0];
    coordinates_[1] += v.coordinates_[1];
    coordinates_[2] += v.coordinates_[2];
    return *this;
}

Vec3& Vec3::operator*=(double t) {
    coordinates_[0] *= t;
    coordinates_[1] *= t;
    coordinates_[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(double t) {
    coordinates_[0] /= t;
    coordinates_[1] /= t;
    coordinates_[2] /= t;
    return *this;
}

double Vec3::length() {
    return sqrt(coordinates_[0] * coordinates_[0] + coordinates_[1] * coordinates_[1] + coordinates_[2] * coordinates_[2]);
}

double Vec3::lengthSquared() {
    return coordinates_[0] * coordinates_[0] + coordinates_[1] * coordinates_[1] + coordinates_[2] * coordinates_[2];
}

bool Vec3::nearZero() const {
    return (fabs(this->coordinates_[0]) < nearZeroThreshold &&
            fabs(this->coordinates_[1]) < nearZeroThreshold &&
            fabs(this->coordinates_[2]) < nearZeroThreshold);
}

Vec3 Vec3::limitToRange(double minVal, double maxVal) {
    Vec3 vec = Vec3(this->coordinates_[0], this->coordinates_[1], this->coordinates_[2]);
    for (double & coordinate : vec.coordinates_) {
        if (coordinate < minVal) {
            coordinate = minVal;
        }
        if (coordinate > maxVal) {
            coordinate = maxVal;
        }
    }
    return vec;
}

Vec3 Vec3::reflect(const Vec3 &v, const Vec3 &normal) {
    return v - 2*dot(v,normal)*normal;
}

Vec3 Vec3::refract(const Vec3 &uv, const Vec3 &normal, double etaiEtat) {
    auto cosTheta = fmin(dot(-uv, normal), 1.0);
    Vec3 rOutPerpendicular = etaiEtat * (uv + cosTheta*normal);
    Vec3 rOutParallel = -sqrt(fabs(1.0 - rOutPerpendicular.lengthSquared())) * normal;
    return rOutPerpendicular + rOutParallel;
}
