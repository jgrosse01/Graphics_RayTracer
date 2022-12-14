// DIRECTLY ADAPTED from Raytracing Into Next Week.

#include "XZRect.h"


XZRect::XZRect(double x0, double x1, double z0, double z1, double k, shared_ptr<MaterialInterface> material) {
    this->x0 = x0;
    this->x1 = x1;
    this->z0 = z0;
    this->z1 = z1;
    this->k = k;
    this->materialPointer_ = material;
}

bool XZRect::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    auto t = (k-r.origin().y()) / r.direction().y();
    if (t < t_min || t > t_max) {
        return false;
    }
    auto x = r.origin().x() + t*r.direction().x();
    auto z = r.origin().z() + t*r.direction().z();

    if (x < x0 || x > x1 || z < z0 || z > z1) {
        return false;
    }

    record.u = (x-x0)/(x1-x0);
    record.v = (z-z0)/(z1-z0);
    record.t = t;

    auto outwardNormal = Vec3(0,1,0);

    record.setFaceNormal(r, outwardNormal);

    record.materialPointer_ = this->materialPointer_;
    record.p = r.at(t);

    return true;
}
