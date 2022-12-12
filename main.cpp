#include <GL/freeglut.h>
#include "src/rt_lib/RTUtilities.h"

int g_width = 600, g_height = 400;
int g_pixelBorder = 30;

PPM* g_ppm;


//void reshape(int w, int h) {
//    g_width= w;
//    g_height = h;
//    glViewport(0, 0, g_width, g_height);
//    glutPostRedisplay();
//}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    for (int j = g_height-1; j >= 0; j--) {
        for (int i = 0; i < g_width; i++) {
            double r, g, b;
            r = g_ppm->at(j,i)[0];
            g = g_ppm->at(j,i)[1];
            b = g_ppm->at(j,i)[2];
            //std::cout << r << " " << g << " " << b  << std::endl;
            glColor3d(r, g, b);
            glVertex2i(i + g_pixelBorder,j + g_pixelBorder);
        }
    }

    glEnd();
    glFlush();
}

void init() {
    // initial load, right now assumes pre-rendered image
//    g_ppm = PPM::loadPPM("raytrace");
//    g_width = g_ppm->width();
//    g_height = g_ppm->height();

    g_ppm = renderScene(g_width, g_height);
    g_ppm->savePPM("raytrace");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.2,0.2,0.2,1.0);
    glOrtho(0, g_width+2*g_pixelBorder, 0, g_height+2*g_pixelBorder, -1, 1);
}

void keys(unsigned char key, int x, int y) {
    switch ( key ) {
        default:
            break;
        // when press L key (without shift), load image from file
        case 'l':
            g_ppm = PPM::loadPPM("raytrace");
            g_width = g_ppm->width();
            g_height = g_ppm->height();
            break;
        // when press s key, save ppm image that is in memory
        case 's':
            g_ppm->savePPM("raytrace");
            break;
        // when press r key, re-render the scene
        case 'r':
            g_ppm = renderScene(g_width, g_height);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(g_width+2*g_pixelBorder, g_height+2*g_pixelBorder);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Raytrace PPM Viewer");

    init();

    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
    glutKeyboardFunc(keys);

    glutMainLoop();

    return 0;
}
