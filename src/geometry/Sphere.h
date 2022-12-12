//
// Code modified from implementation seen in "Ray Tracing in One Weekend" by Peter Shirley
//

#ifndef GL_RAYTRACER_SPHERE_H
#define GL_RAYTRACER_SPHERE_H

#include "../rt_lib/Hittable.h"
#include "../rt_lib/RandomUtilites.h"

class Sphere : public Hittable {
private:
    static void getSphereUV(Vec3 p, double& u, double& v);

public:
    Point3 center;
    double radius;
    Color color;
    shared_ptr<MaterialInterface> materialPointer;

    Sphere(Point3 center, double radius, shared_ptr<MaterialInterface> mat);

    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;
};


#endif //GL_RAYTRACER_SPHERE_H
