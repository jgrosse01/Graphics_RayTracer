//
// Created by jgros on 11/1/2022.
//

#include "ppm.h"
#include <vector>
#include <fstream>

PPM::PPM(color* pixels, int w) {

}

PPM::PPM(int w, int h) {
    this->width = w;
    this->height = h;
    pixels = new color[width*height];
}

int PPM::getWidth() {
    return this->width;
}

int PPM::getHeight() {
    return this->height;
}

color& PPM::at(int r, int c) {
    return pixels[r*width + c];
}

color* PPM::getPixels() {

}

void PPM::savePPM(const string& name) {
    std::ofstream img("./images/" + name + ".ppm");
    img << "P3 " << this->width << " " << this->height << " 255\n";
    for (int j = this->height-1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            writeColor(img, this->at(j,i));
        }
    }
    img.close();
}

void PPM::writeColor(std::ostream &output, color c) {
    output << static_cast<int>(255.999 * c[0]) << ' '
        << static_cast<int>(255.999 * c[1]) << ' '
        << static_cast<int>(255.999 * c[2]) << '\n';
}

PPM::~PPM() {
    delete[] pixels;
}
