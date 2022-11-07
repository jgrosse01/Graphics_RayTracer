//
// Created by jgros on 11/1/2022.
//

#include "Triangle.h"


Triangle::Triangle(float *point1, float *point2, float *point3, float *location, float *rotation, int *color) {
    this->point1 = point1;
    this->point2 = point2;
    this->point3 = point3;
    this->location = location;
    this->rotation = rotation;
    this->color = color;
}

void Triangle::draw() {
    // draw triangle without affecting the overall ModelView Matrix
    glPushMatrix();

    glRotatef(rotation[0], 1, 0, 0);
    glRotatef(rotation[1], 0, 1, 0);
    glRotatef(rotation[2], 0, 0, 1);

    glPushAttrib(GL_COLOR);
    glColor4ub(color[0], color[1], color[2], color[3]);

    glBegin(GL_TRIANGLES);
    glVertex3f(point1[0]+location[0], point1[1]+location[1], point1[2]+location[2]);
    glVertex3f(point2[0]+location[0], point2[1]+location[1], point2[2]+location[2]);
    glVertex3f(point3[0]+location[0], point3[1]+location[1], point3[2]+location[2]);
    glEnd();

    glPopAttrib();
    glPopMatrix();
}

void Triangle::updateLocation(float x, float y, float z) {
    this->location[0] = x;
    this->location[1] = y;
    this->location[2] = z;
}

void Triangle::updateRotation(float xAngle, float yAngle, float zAngle) {
    this->rotation[0] = xAngle;
    this->rotation[1] = yAngle;
    this->rotation[2] = zAngle;
}

Triangle::~Triangle() {
    delete[] point1;
    delete[] point2;
    delete[] point3;
    delete[] rotation;
    delete[] location;
    delete[] color;
}
