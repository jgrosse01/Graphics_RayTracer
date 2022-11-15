/*
 * Generic implementation of a virtual camera to be used to cast rays from.
 * Author: Jake Grosse (11/15/2022)
 */

#include "Camera.h"

Camera::Camera(Vec3 origin, float aspectRatio, float focalLength,  float viewportHeight) {
    this->origin = origin;
    this->aspect = aspectRatio;
    this->focal = focalLength;
    this->vpHeight = viewportHeight;

    this->vpWidth = aspect*vpHeight;
    this->horizontal = Vec3(vpWidth, 0.0, 0.0);
    this->vertical = Vec3(0.0, vpHeight, 0.0);
    this->lowerLeftCorner = origin - horizontal/2 - vertical/2 - Vec3(0,0,focal);
}

Ray Camera::getRay(double u, double v) {
    return {origin, lowerLeftCorner + u*horizontal + v*vertical - origin};
}
