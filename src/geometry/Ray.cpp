//
// Created by jgros on 11/1/2022.
//

#include "Ray.h"

Ray::Ray(int *origin, const float *point1, const float *point2) {
    this->origin_point = origin;
    Ray::calcDirectionUnitVector(this->direction, point1, point2);
}
