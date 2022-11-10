/*
 * PPM class to store and manage screen size pixel color values.
 * Author: Jacob Grosse (1 November 2022)
 */

#ifndef GL_RAYTRACER_PPM_H
#define GL_RAYTRACER_PPM_H

#include <GL/freeglut.h>
#include <vector>
#include "../rt_lib/Vec3.h"
#include <fstream>

using std::string;

class PPM {
private:
    Color* pixels_;
    int width_;
    int height_;

    static void writeColor(std::ostream &output, Color c);

public:
    PPM(int w, int h);

    int width();
    int height();

    Color& at(int r, int c);

    void savePPM(const string& filename);

    ~PPM();
};

#endif //GL_RAYTRACER_PPM_H
