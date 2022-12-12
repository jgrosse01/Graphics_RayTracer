//
// Created by jgros on 12/12/2022.
//

#ifndef GL_RAYTRACER_SOLIDCOLOR_H
#define GL_RAYTRACER_SOLIDCOLOR_H

#include "TextureInterface.h"


class SolidColor : public TextureInterface{
private:
    Color colorValue;
public:
    SolidColor() {};
    SolidColor(Color color);
    SolidColor(double red, double green, double blue);

    virtual Color value(double u, double v, const Point3& p) const override;
};


#endif //GL_RAYTRACER_SOLIDCOLOR_H
