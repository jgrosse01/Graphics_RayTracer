/*
 * RTUtilities serves the purpose of providing some miscellaneous functions that are necessary for the RT process.
 * Author: Jacob Grosse (10 November 2022)
 */

#ifndef GL_RAYTRACER_RTUTILITIES_H
#define GL_RAYTRACER_RTUTILITIES_H

#include <limits>
#include <random>
#include "Vec3.h"
#include "HittableList.h"
#include "../geometry/Sphere.h"
#include "../ppm/PPM.h"
#include "Camera.h"

using namespace std;
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

static std::uniform_real_distribution<double> s_distribution(0.0, 1.0);
static std::mt19937 s_generator;

const double c_infinity = std::numeric_limits<double>::infinity();
const double c_pi = 3.1415926535897932385;

PPM* renderScene(int width, int height, int samplesPerPixel = 100);

Color rayColor(const Ray& r, const hittable& world);

double randomDouble();

double degreesToRadians(double degrees);

#endif //GL_RAYTRACER_RTUTILITIES_H
