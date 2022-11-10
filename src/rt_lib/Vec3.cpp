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
