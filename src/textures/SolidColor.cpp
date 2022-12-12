//
// Created by jgros on 12/12/2022.
//

#include "SolidColor.h"

SolidColor::SolidColor(Color color) {
    this->colorValue = color;
}

SolidColor::SolidColor(double red, double green, double blue) {
    this->colorValue = Color(red, green, blue);
}

Color SolidColor::value(double u, double v, const Point3& p) const {
    return this->colorValue;
}