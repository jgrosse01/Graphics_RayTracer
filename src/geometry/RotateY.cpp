//
// Created by jgros on 12/14/2022.
//

#include "RotateY.h"

RotateY::RotateY(shared_ptr<Hittable> obj, double angle) {
    auto radians = angle * (c_pi/180);
    this->obj_ = obj;
    this->sinTheta_ = sin(radians);
    this->cosTheta_ = cos(radians);
}

bool RotateY::hit(const Ray &r, double t_min, double t_max, HitRecord &record) const {
    auto origin = r.origin();
    auto direction = r.direction();
    
    origin.setX(this->cosTheta_*r.origin()[0] - this->sinTheta_*r.origin()[2]);
    origin.setZ(this->sinTheta_*r.origin()[0] + this->cosTheta_*r.origin()[2]);
    
    direction.setX(this->cosTheta_*r.direction()[0] - this->sinTheta_*r.direction()[2]);
    direction.setZ(this->sinTheta_*r.direction()[0] + this->cosTheta_*r.direction()[2]);
    
    Ray rotated = Ray(origin, direction);
    
    if (!this->obj_->hit(rotated, t_min, t_max, record)) {
        return false;
    }
    
    auto p = record.p;
    auto normal = record.normal;
    
    p.setX(cosTheta_*record.p[0] + sinTheta_*record.p[2]);
    p.setZ(-sinTheta_*record.p[0] + cosTheta_*record.p[2]);

    normal.setX(cosTheta_*record.normal[0] + sinTheta_*record.normal[2]);
    normal.setZ(-sinTheta_*record.normal[0] + cosTheta_*record.normal[2]);

    record.p = p;
    record.normal = normal;

    return true;
}
