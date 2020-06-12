#include<iostream>
#include<GL/glut.h>
#include<Torus.h>


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Torus");
    glOrtho(-100, 100, -100, 100, -100, 100);
    glRotatef(60, 1, 0, 0);

    Torus torus;
    torus.print_controls();

    glutDisplayFunc(torus.display);
    glutIdleFunc(torus.display);
    glutKeyboardFunc(torus.kbin);

    glutMainLoop();
	return 0;
}
