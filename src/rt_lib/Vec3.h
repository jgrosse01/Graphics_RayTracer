/*
 * Vec3 is a simple implementation of a three-dimensional vector.
 * Author: Jacob Grosse (10 November, 2022)
 */

#ifndef GL_RAYTRACER_VEC3_H
#define GL_RAYTRACER_VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3 {
protected:
    double coordinates_[3]{};

public:
    Vec3();
    Vec3(double x, double y, double z);

    double x();
    double y();
    double z();

    Vec3 operator-() const;
    double operator[](int i) const;
    Vec3& operator+=(const Vec3 &v);
    Vec3& operator*=(double t);
    Vec3& operator/=(double t);
    double length();
    double lengthSquared();
};

// Type aliases for Vec3 to make code more readable.
using Point3 = Vec3;   // Used to represent a point in 3D space.
using Color = Vec3;    // Used to represent RGB Color.

// Vec3 Utility Operators

// output operator
inline std::ostream& operator<<(std::ostream &out, const Vec3 v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

// two vector addition
inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return {u[0] + v[0], u[1] + v[1], u[2] + v[2]};
}

// two vector subtraction
inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return {u[0] - v[0], u[1] - v[1], u[2] - v[2]};
}

// two vector straight multiplication (not cross or dot multiplication)
inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return {u[0] * v[0], u[1] * v[1], u[2] * v[2]};
}

// constant-vector multiplication
inline Vec3 operator*(double t, const Vec3 &v) {
    return {t*v[0], t * v[1], t * v[2]};
}

// vector-constant multiplication
inline Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

// vector-constant division
inline Vec3 operator/(Vec3 v, double t) {
    return (1/t) * v;
}

// two vector dot product
inline double dot(const Vec3 &u, const  Vec3 &v) {
    return u[0] * v[0]
           + u[1] * v[1]
           + u[2] * v[2];
}

// two vector cross product
inline Vec3 cross(Vec3 &u, Vec3 &v) {
    return {u[1] * v[2] - u[2] * v[1],
            u[2] * v[0] - u[0] * v[2],
            u[0] * v[1] - u[1] * v[0]};
}

inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

#endif //GL_RAYTRACER_VEC3_H

