/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#ifndef GL_RAYTRACER_RTUTILITIES_H
#define GL_RAYTRACER_RTUTILITIES_H

#include <limits>
#include "Vec3.h"
#include "RandomUtilites.h"
#include "HittableList.h"
#include "../geometry/Sphere.h"
#include "../ppm/PPM.h"
#include "Camera.h"
#include "../materials/LambertianDiffuseMaterial.h"
#include "../materials/Metal.h"
#include "../materials/Dielectric.h"


PPM* renderScene(int width, int height, int samplesPerPixel = 50, int rayDepth = 20);

Color rayColor(const Ray& r, const Hittable& world, int depth);

double degreesToRadians(double degrees);

#endif //GL_RAYTRACER_RTUTILITIES_H
