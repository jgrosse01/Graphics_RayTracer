//
// Code modified from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
//
#include "Sphere.h"

Sphere::Sphere(Point3 center, double radius, shared_ptr<MaterialInterface> mat) {
    this->center = center;
    this->radius = radius;
    this->materialPointer = mat;
}

bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 oc = r.origin() - center;
    auto a = r.direction().lengthSquared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.lengthSquared() - radius * radius;

    auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    Vec3 outward_normal = (rec.p - center) / radius;
    rec.setFaceNormal(r, outward_normal);
    getSphereUV(outward_normal, rec.u, rec.v);
    rec.materialPointer_ = this->materialPointer;

    return true;
}

void Sphere::getSphereUV(Vec3 p, double &u, double &v) {
    auto theta = acos(-p.y());
    auto phi = atan2(-p.z(), p.x()) + c_pi;

    u = phi/(2*c_pi);
    v = theta/phi;
}
