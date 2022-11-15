/*
 * Generic implementation of a virtual camera to be used to cast rays from.
 * Author: Jake Grosse (11/15/2022)
 */

#ifndef GL_RAYTRACER_CAMERA_H
#define GL_RAYTRACER_CAMERA_H


#include "Vec3.h"
#include "Ray.h"

class Camera {
private:
    double aspect;
    double vpHeight;
    double vpWidth;
    double focal;

    Point3 origin;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 lowerLeftCorner;

public:
    explicit Camera(double aspectRatio = 16.0/9.0, Vec3 origin = Vec3(0,0,0), double focalLength = 1.0, double viewportHeight = 2.0);

    Ray getRay(double u, double v);
};


#endif //GL_RAYTRACER_CAMERA_H
