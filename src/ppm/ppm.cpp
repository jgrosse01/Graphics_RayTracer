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

int PPM::width() const {
    return this->width_;
}

int PPM::height() const {
    return this->height_;
}

Color& PPM::at(int r, int c) {
    return pixels_[r * width_ + c];
}

PPM* PPM::loadPPM(const string& name) {
    std::ifstream ppmFile("./images/" + name + ".ppm");

    // get format stuff
    string ppmFormat;
    int width, height, maxColor;
    ppmFile >> ppmFormat;
    ppmFile >> width;
    ppmFile >> height;
    ppmFile >> maxColor;

    //std::cout << ppmFormat << " " << width << " " << height << " " << maxColor << std::endl;

    PPM* ppm = new PPM(width, height);
    for (int j = ppm->height() - 1; j >= 0; j--) {
        for (int i = 0; i < ppm->width(); i++) {
            double r, g, b;
            ppmFile >> r;
            ppmFile >> g;
            ppmFile >> b;
            //std::cout << r/maxColor << " " << g/maxColor << " " << b/maxColor << " " << std::endl;
            ppm->at(j,i) = Color(r/maxColor,g/maxColor,b/maxColor);
        }
    }

    ppmFile.close();

    return ppm;
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
