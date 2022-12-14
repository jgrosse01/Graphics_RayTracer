// DIRECTLY ADAPTED from Raytracing Into Next Week.

#include "XYRect.h"

XYRect::XYRect(double x0, double x1, double y0, double y1, double k, shared_ptr<MaterialInterface> material) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->k = k;
    this->materialPointer_ = material;
}

bool XYRect::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    auto t = (k-r.origin().z())/r.direction().z();
    if (t < t_min || t > t_max) {
        return false;
    }
    auto x = r.origin().x() + t*r.direction().x();
    auto y = r.origin().y() + t*r.direction().y();

    if (x < x0 || x > x1 || y < y0 || y > y1) {
        return false;
    }

    record.u = (x-x0)/(x1-x0);
    record.v = (y-y0)/(y1-y0);
    record.t = t;

    auto outwardNormal = Vec3(0,0,1);

    record.setFaceNormal(r, outwardNormal);

    record.materialPointer_ = this->materialPointer_;
    record.p = r.at(t);

    return true;
}
