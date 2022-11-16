/*
 * Code directly adapted from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
 */

#include "Ray.h"

Ray::Ray() {

}

Ray::Ray(const Point3 &origin, const Vec3 &direction) {
    this->origin_ = origin;
    this->direction_ = direction;
}

Point3 Ray::origin() const{
    return this->origin_;
}

Vec3 Ray::direction() const{
    return this->direction_;
}

Point3 Ray::at(double t) const{
    return origin_ + (t * direction_);
}
