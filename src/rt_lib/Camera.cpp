/*
 * Generic implementation of a virtual camera to be used to cast rays from.
 * Author: Jake Grosse (11/15/2022)
 */

#include "Camera.h"

Camera::Camera(Vec3 origin, Vec3 lookAt, double aspectRatio, double FOV, Vec3 upDirection) {
    auto theta = FOV * (c_pi/180.0);
    auto height = tan(theta/2);
    auto viewportHeight = 2.0*height;
    auto viewportWidth = aspectRatio * viewportHeight;

    auto w = unitVector(origin-lookAt);
    auto u = unitVector(cross(upDirection, w));
    auto v = cross(w,u);

    this->origin = origin;
    this->horizontal = viewportWidth*u;
    this->vertical = viewportHeight*v;
    this->lowerLeftCorner = origin - horizontal/2 - vertical/2 - w;
}

Ray Camera::getRay(double u, double v) {
    return {origin, lowerLeftCorner + u*horizontal + v*vertical - origin};
}
