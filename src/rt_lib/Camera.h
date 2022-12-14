/*
 * Generic implementation of a virtual camera to be used to cast rays from.
 * Author: Jake Grosse (11/15/2022)
 */

#ifndef GL_RAYTRACER_CAMERA_H
#define GL_RAYTRACER_CAMERA_H


#include "Vec3.h"
#include "Ray.h"
#include "RandomUtilites.h"

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
    explicit Camera(Vec3 origin = {0,0,0}, Vec3 lookAt = {0,0,1}, double aspectRatio = 16.0/9.0, double FOV = 90.0, Vec3 upDirection = {0,1,0});

    Ray getRay(double u, double v);
};


#endif //GL_RAYTRACER_CAMERA_H
