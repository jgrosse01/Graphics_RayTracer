//
// Created by jgros on 11/1/2022.
//

#ifndef GL_RAYTRACER_TRIANGLE_H
#define GL_RAYTRACER_TRIANGLE_H

float defaultPoint1[] = {0,1,0};
float defaultPoint2[] = {0.5,0,0};
float defaultPoint3[] = {-0.5, 0, 0};
float defaultLocation[] = {0,0,0};
float defaultRotation[] = {0,0,0};
int defaultColor[] = {255,0,50,255};

class Triangle {
private:
    float* point1;
    float* point2;
    float* point3;
    float* location;
    float* rotation;
    int* color;

public:
    explicit Triangle(float point1[3] = defaultPoint1,
                      float point2[3] = defaultPoint2,
                      float point3[3] = defaultPoint3,
                      float location[3] = defaultLocation,
                      float rotation[3] = defaultRotation,
                      int color[4] = defaultColor);
    void draw();
    void updateLocation(float x, float y, float z);
};


#endif //GL_RAYTRACER_TRIANGLE_H
