//
// Created by jgros on 11/1/2022.
//

#ifndef GL_RAYTRACER_PPM_H
#define GL_RAYTRACER_PPM_H

class PPM {
private:
    std::vector<GLubyte[4]> *pixels;

public:
    PPM(std::vector<GLubyte[4]> *pixels);

    std::vector<GLubyte[4]>* getPixels();

//    NYI
//    static PPM saveppm(char* filepath);
//    static PPM loadppm(char* filepath);
};

#endif //GL_RAYTRACER_PPM_H
