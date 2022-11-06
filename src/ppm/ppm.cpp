//
// Created by jgros on 11/1/2022.
//

#include "ppm.h"
#include <vector>
#include <fstream>

PPM::PPM(std::vector<std::vector<color>> *pixels) {
    this->pixels = pixels;
}

std::vector<std::vector<color>>* PPM::getPixels() {
    std::vector<std::vector<color>>* new_ = this->pixels;
    return new_;
}

void PPM::saveppm(char *filepath, PPM ppm_image) {
    // create new file
    std::ofstream img("saved_files/raytrace.ppm");
    // write header line
    int width = ppm_image.pixels->size();
    int height = ppm_image.pixels[0].size();
    img << "P3 " << width << " " << height << " " << 255 << std::endl;
    // iterative loops to save RGB color info to ppm
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            img << ppm_image.pixels[i][j][0] << " " << ppm_image.pixels[i][j][1] << " " << ppm_image.pixels[i][j][2] << std::endl;
        }
    }
    img.close();
}

PPM PPM::loadppm(char *filepath) {
    return PPM(nullptr);
}



