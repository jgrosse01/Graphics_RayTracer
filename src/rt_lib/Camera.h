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
    float aspect;
    float vpHeight;
    float vpWidth;
    float focal;

    Point3 origin;
    Vec3 horizontal;
    Vec3 vertical;
    Vec3 lowerLeftCorner;

public:
    explicit Camera(Vec3 origin = Vec3(0,0,0), float aspectRatio = 16.0/9.0, float focalLength = 1.0, float viewportHeight = 2.0);

    Ray getRay(double u, double v);
};


#endif //GL_RAYTRACER_CAMERA_H
