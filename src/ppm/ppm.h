//
// Created by jgros on 11/1/2022.
//

#ifndef GL_RAYTRACER_PPM_H
#define GL_RAYTRACER_PPM_H

#include <GL/freeglut.h>
#include <vector>
#include "../rt_lib/vec3.h"

using std::string;

class PPM {
private:
    color* pixels;
    int width;
    int height;

    void writeColor(std::ostream &output, color c);

public:
    PPM(color* pixels, int w);
    PPM(int w, int h);

    int getWidth();
    int getHeight();

    color& at(int r, int c);

    color* getPixels();

    void savePPM(const string& filename);

    ~PPM();
};

#endif //GL_RAYTRACER_PPM_H
