//
// Created by Jake on 11/16/2022.
//

#ifndef GL_RAYTRACER_RANDOMUTILITES_H
#define GL_RAYTRACER_RANDOMUTILITES_H

#include <random>
#include <memory>
#include <cmath>
#include "Vec3.h"

using namespace std;
using std::shared_ptr;
using std::make_shared;
using std::sqrt;
using std::pow;

const double c_infinity = std::numeric_limits<double>::infinity();
const double c_pi = 3.1415926535897932385;

static std::uniform_real_distribution<double> s_distribution(0.0, 1.0);
static std::mt19937 s_generator;

double randomDouble();
double randomDouble(double min, double max);

Vec3 randomVector();
Vec3 randomVector(double min, double max);
Vec3 randomVectorInUnitSphere();
Vec3 randomUnitVector();
Vec3 randomVectorInHemisphere(const Vec3 &normalVector);

#endif //GL_RAYTRACER_RANDOMUTILITES_H
