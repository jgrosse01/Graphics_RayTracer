//
// Created by jgros on 12/14/2022.
//

#include "Translate.h"

Translate::Translate(shared_ptr<Hittable> obj, const Vec3 &displacement) {
    this->obj_ = obj;
    this->offset_ = displacement;
}

bool Translate::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    Ray offsetRay = {r.origin() - this->offset_, r.direction()};

    if (!this->obj_->hit(offsetRay, t_min, t_max, record)) {
        return false;
    }

    record.p += offset_;
    record.setFaceNormal(offsetRay, record.normal);

    return true;
}
