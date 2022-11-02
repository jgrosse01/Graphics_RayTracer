//
// Created by jgros on 11/1/2022.
//

#ifndef GL_RAYTRACER_RAY_H
#define GL_RAYTRACER_RAY_H

#include <cmath>

class Ray {
private:
    float* direction;
    int* origin_point;

public:
    Ray(int origin[3], const float* point1, const float* point2);

    static float* calcDirectionUnitVector(float* dirVec, const float point1[3], const float point2[3]) {
        dirVec[0] = point2[0] - point1[0];
        dirVec[1] = point2[1] - point1[1];
        dirVec[2] = point2[2] - point1[2];
        float mag = std::sqrt(dirVec[0]*dirVec[0] + dirVec[1]*dirVec[1] + dirVec[2]*dirVec[2]);
        for (int i = 0; i < 3; i++) {
            dirVec[i] = dirVec[i]/mag;
        }
        return dirVec;
    }
};


#endif //GL_RAYTRACER_RAY_H
