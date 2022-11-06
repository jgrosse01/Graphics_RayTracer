#include <GL/freeglut.h>
#include <vector>
#include <cmath>
#include <limits>
#include <memory>
#include <iostream>

#include "src/geometry/Triangle.h"
#include "src/geometry/Sphere.h"
#include "src/geometry/Ray.h"
#include "src/geometry/vec3.h"
#include "src/geometry/hittable_list.h"
#include "src/ppm/ppm.h"


// some utility

using namespace std;
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

/*
 * Begin Main
 */

bool testing = true;

int width = 600, height = 400;

// boolean to swap between render and non-render for potential future
// implementation of movement (save a static scene and have the ability
// move the camera without modifying saved scene)
bool displayPPM = false;

// lighting
GLfloat global_ambient_lighting[4] = {0.1,0.1,0.1,1.0};
GLfloat light0_ambient[4] = {0.2,0.2,0.2,0.5};
GLfloat light0_diffuse[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat light0_specular[4] = {1.0, 1.0, 1.0, 1.0};
GLfloat light0_pos[3] = {-10,1,0};

GLfloat cameraLocation[3] = {0,1,-10};

vector<vector<color>> *pixels;

PPM* savedPPM;

Triangle* t1 = new Triangle();


void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glFlush();
    glutSwapBuffers();
}

void reshape(int x, int y) {
    width = x;
    height = y;
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, width/(height*1.0), 0, 10);
    glOrtho(-2, 2, -2, 2, 1, 100);
    gluLookAt(cameraLocation[0], cameraLocation[1], cameraLocation[2],
              0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
}

void idle() {}

void init() {
    glEnable(GL_DEPTH_TEST | GL_DEPTH | GL_CULL_FACE | GL_NORMALIZE);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);
    glViewport(0,0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90, width/(height*1.0), 0, 10);
    glOrtho(-2, 2, -2, 2, 1, 100);
    gluLookAt(cameraLocation[0], cameraLocation[1], cameraLocation[2],
              0, 0, 0, 0, 1, 0);
    glClearColor(0,0,0,0);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_lighting);
    glEnable(GL_LIGHTING | GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
}

void renderScene() {
    hittable_list world;
    world.add( make_shared<Sphere>( point3(-1,1,-10), 1, color(0.5,1,0.5) ) );
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rudimentary CPU RayTracer");

    renderScene();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    init();

    glutMainLoop();

    delete(t1);
    delete(savedPPM);

    return 0;
}
