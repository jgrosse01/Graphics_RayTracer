/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#ifndef GL_RAYTRACER_RTUTILITIES_H
#define GL_RAYTRACER_RTUTILITIES_H

#include <limits>
#include "Vec3.h"
#include "HittableList.h"
#include "../geometry/Sphere.h"
#include "../ppm/PPM.h"
#include "Camera.h"

using namespace std;
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double c_infinity = std::numeric_limits<double>::infinity();
const double c_pi = 3.1415926535897932385;

PPM* renderScene(int width, int height);

Color rayColor(const Ray& r, const hittable& world);

double degreesToRadians(double degrees);

#endif //GL_RAYTRACER_RTUTILITIES_H
