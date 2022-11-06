//
// Code modified from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
//
#include <GL/freeglut.h>

#include "Sphere.h"

Sphere::Sphere(point3 center, double radius, ::color color) {
    this->center = center;
    this->radius = radius;
    this->color = color;
}

void Sphere::draw() {
    // draw triangle without affecting the overall ModelView Matrix
    glPushMatrix();
    glPushAttrib(GL_COLOR);
    glColor3d(this->color[0], this->color[1], this->color[2]);
    glTranslated(this->center[0], this->center[1], this->center[2]);
    gluSphere(gluNewQuadric(), this->radius, 50, 50);
    glPopAttrib();
    glPopMatrix();
}

bool Sphere::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

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
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
}
