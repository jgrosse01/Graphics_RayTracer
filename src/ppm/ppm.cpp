/*
 * PPM class to store and manage screen size pixel color values.
 * Author: Jacob Grosse (1 November 2022)
 */

#include "PPM.h"

PPM::PPM(int w, int h) {
    this->width_ = w;
    this->height_ = h;
    pixels_ = new Color[width_ * height_];
}

int PPM::width() {
    return this->width_;
}

int PPM::height() {
    return this->height_;
}

Color& PPM::at(int r, int c) {
    return pixels_[r * width_ + c];
}

void PPM::savePPM(const string& name) {
    std::ofstream img("./images/" + name + ".ppm");
    img << "P3 " << this->width_ << " " << this->height_ << " 255\n";
    for (int j = this->height_ - 1; j >= 0; j--) {
        for (int i = 0; i < width_; i++) {
            writeColor(img, this->at(j,i));
        }
    }
    img.close();
}

void PPM::writeColor(std::ostream &output, Color c) {
    c = c.limitToRange(0.0, 0.999);
    output << static_cast<int>(256 * c[0]) << ' '
        << static_cast<int>(256 * c[1]) << ' '
        << static_cast<int>(256 * c[2]) << '\n';
}

PPM::~PPM() {
    delete[] pixels_;
}
