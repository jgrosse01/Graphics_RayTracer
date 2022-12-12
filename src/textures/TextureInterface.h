//
// Created by jgros on 12/12/2022.
//

#ifndef GL_RAYTRACER_TEXTURE_H
#define GL_RAYTRACER_TEXTURE_H

#include "../rt_lib/Vec3.h"


class Texture {
public:
    virtual Color value(double u, double v, const Point3& p) const = 0;
};


#endif //GL_RAYTRACER_TEXTURE_H
