//
// Created by jgros on 12/12/2022.
//

#include "Rectangle.h"

Rectangle::Rectangle(double x0, double x1, double y0, double y1, double k, shared_ptr<MaterialInterface> material) {

}

bool Rectangle::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    return false;
}
