#include <GL/freeglut.h>
#include <vector>
#include <iostream>
#include "src/ppm/ppm.cpp"
#include "src/geometry/Ray.cpp"
#include "src/geometry/Triangle.cpp"

using namespace std;

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

vector<GLubyte[4]> *pixels;

PPM* savedPPM;

Triangle* t1 = new Triangle();

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    t1->draw();

    glFlush();
    glutSwapBuffers();
}

void reshape(int x, int y) {
    width = x;
    height = y;
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90, width/(height*1.0), 0, 150);
    glOrtho(-2, 2, -2, 2, 1, 100);
    gluLookAt(cameraLocation[0], cameraLocation[1], cameraLocation[2],
              0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
}

void idle() {}

void keys(unsigned char key, int x, int y) {
    switch (key) {
        default:
            break;
        case 'S':
            // free up memory before reassigning to avoid memory leaks
            delete(savedPPM);
            glReadPixels(0,0,width,height,GL_RGBA,GL_FLOAT, &pixels);
            savedPPM = new PPM(pixels);
        case 'p':
            displayPPM = !displayPPM;
            glutPostRedisplay();
    }
}

void init() {
    glEnable(GL_DEPTH_TEST | GL_NORMALIZE);
    glViewport(0,0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90, width/(height*1.0), 0, 150);
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

int main(int argc, char** argv) {
    // Testing Code
    if (testing) {
        float dirVec[3] = {0,0,0};
        float point1[3] = {0,0,0};
        float point2[3] = {2,2,2};
        float* dirVec1 = Ray::calcDirectionUnitVector(dirVec, point1, point2);
        float* dirVec2 = Ray::calcDirectionUnitVector(dirVec, point2, point1);

        cout << dirVec1[0] << " " << dirVec1[1] << " " << dirVec1[2] << endl;
        cout << dirVec2[0] << " " << dirVec2[1] << " " << dirVec2[2] << endl;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rudimentary CPU RayTracer");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keys);

    init();

    glutMainLoop();

    delete(t1);
    delete(savedPPM);

    return 0;
}
