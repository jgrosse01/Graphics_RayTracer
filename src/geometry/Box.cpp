//
// Created by jgros on 12/14/2022.
//

#include "Box.h"

Box::Box(const Vec3 &p0, const Vec3 &p1, shared_ptr<MaterialInterface> material) {
    this->boxMin_ = p0;
    this->boxMax_ = p1;

    sides_.add(make_shared<XYRect>(boxMin_.x(), boxMax_.x(), boxMin_.y(), boxMax_.y(), boxMax_.z(), material));
    sides_.add(make_shared<XYRect>(boxMin_.x(), boxMax_.x(), boxMin_.y(), boxMax_.y(), boxMin_.z(), material));

    sides_.add(make_shared<XZRect>(boxMin_.x(), boxMax_.x(), boxMin_.z(), boxMax_.z(), boxMax_.y(), material));
    sides_.add(make_shared<XZRect>(boxMin_.x(), boxMax_.x(), boxMin_.z(), boxMax_.z(), boxMin_.y(), material));

    sides_.add(make_shared<YZRect>(boxMin_.y(), boxMax_.y(), boxMin_.z(), boxMax_.z(), boxMax_.x(), material));
    sides_.add(make_shared<YZRect>(boxMin_.y(), boxMax_.y(), boxMin_.z(), boxMax_.z(), boxMin_.x(), material));
}

bool Box::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    return sides_.hit(r, t_min, t_max, record);
}
