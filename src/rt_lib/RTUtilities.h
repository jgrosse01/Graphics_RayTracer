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
#include "../materials/DiffuseLight.h"
#include "../geometry/XYRect.h"
#include "../geometry/YZRect.h"
#include "../geometry/XZRect.h"
#include "../geometry/Box.h"
#include "../geometry/Translate.h"
#include "../geometry/RotateY.h"

void renderBalls(HittableList* world);

void renderCornell(HittableList* world);

PPM* renderScene(int width, int height, int samplesPerPixel = 10, int rayDepth = 10, char scene = 'c');

PPM* renderScene(PPM* existing, int width, int height, int samplesPerPixel = 100, int rayDepth = 10, char scene = 'c');

Color rayColor(const Ray& r, const Color& background, const Hittable& world, int depth);

#endif //GL_RAYTRACER_RTUTILITIES_H
