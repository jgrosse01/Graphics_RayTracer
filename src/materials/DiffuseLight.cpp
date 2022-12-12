//
// Created by jgros on 12/12/2022.
//

#include "DiffuseLight.h"

DiffuseLight::DiffuseLight(shared_ptr<TextureInterface> a) {
    this->emit_ = a;
}

DiffuseLight::DiffuseLight(Color color) {
    this->emit_ = make_shared<SolidColor>(color);
}

bool DiffuseLight::scatter(const Ray &rayIn, const HitRecord &record, Color &attenuation, Ray &scattered) const {
    return false;
}

Color DiffuseLight::emitted(double u, double v, const Point3 &p) const {
    return emit_->value(u,v,p);
}
