//
// Created by jgros on 11/1/2022.
//

#include "ppm.h"

#include <utility>
#include <vector>

PPM::PPM(std::vector<GLubyte[4]> *pixels) {
    this->pixels = pixels;
}

std::vector<GLubyte[4]>* PPM::getPixels() {
    std::vector<GLubyte[4]>* new_ = this->pixels;
    return new_;
}



