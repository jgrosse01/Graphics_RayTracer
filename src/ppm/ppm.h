//
// Created by jgros on 11/1/2022.
//

#ifndef GL_RAYTRACER_PPM_H
#define GL_RAYTRACER_PPM_H

#include <GL/freeglut.h>
#include <vector>
#include "../geometry/vec3.h"

class PPM {
private:
    std::vector<std::vector<color>> *pixels;

public:
    explicit PPM(std::vector<std::vector<color>> *pixels);

    std::vector<std::vector<color>>* getPixels();

    static void saveppm(char* filepath, PPM ppm_image);
    static PPM loadppm(char* filepath);
};

#endif //GL_RAYTRACER_PPM_H
