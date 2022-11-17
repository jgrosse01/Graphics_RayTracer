#include <GL/freeglut.h>
#include "src/rt_lib/RTUtilities.h"

int g_width = 1000, g_height = 750;
int g_pixelBorder = 50;

PPM* g_ppm;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for (int j = g_height-1; j >= 0; j--) {
        for (int i = 0; i < g_width; i++) {
            glColor3d(g_ppm->at(j, i)[0], g_ppm->at(j,i)[1], g_ppm->at(j,i)[2]);
            glVertex2i(i + g_pixelBorder,j + g_pixelBorder);
        }
    }

    glEnd();
    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.2,0.2,0.2,1.0);
    glOrtho(0, g_width+2*g_pixelBorder, 0, g_height+2*g_pixelBorder, -1, 1);
}

void reshape(int w, int h) {

}

int main(int argc, char** argv) {
    g_ppm = renderScene(g_width, g_height);
    g_ppm->savePPM("raytrace");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(g_width+2*g_pixelBorder, g_height+2*g_pixelBorder);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Raytrace PPM Viewer");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
