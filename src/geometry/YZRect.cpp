//
// Created by jgros on 12/12/2022.
//

#include "YZRect.h"

YZRect::YZRect(double y0, double y1, double z0, double z1, double k, shared_ptr<MaterialInterface> material) {
    this->z0 = z0;
    this->z1 = z1;
    this->y0 = y0;
    this->y1 = y1;
    this->k = k;
    this->materialPointer_ = material;
}

bool YZRect::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    auto t = (k-r.origin().x()) / r.direction().x();
    if (t < t_min || t > t_max) {
        return false;
    }
    auto y = r.origin().y() + t*r.direction().y();
    auto z = r.origin().z() + t*r.direction().z();

    if (y < y0 || y > y1 || z < z0 || z > z1) {
        return false;
    }

    record.u = (y-y0)/(y1-y0);
    record.v = (z-z0)/(z1-z0);
    record.t = t;

    auto outwardNormal = Vec3(1,0,0);

    record.setFaceNormal(r, outwardNormal);

    record.materialPointer_ = this->materialPointer_;
    record.p = r.at(t);

    return true;
}
