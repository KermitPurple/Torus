#include<iostream>
#include<GL/glut.h>
#include<Torus.h>

Torus torus;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    torus.draw();
    glutSwapBuffers();
}

void kbin(unsigned char key, int x, int y){
    switch(key){
        case 'w':
            glRotatef(1, 1, 0, 0);
            break;
        case 'a':
            glRotatef(1, 0, 0, -1);
            break;
        case 's':
            glRotatef(1, -1, 0, 0);
            break;
        case 'd':
            glRotatef(1, 0, 0, 1);
            break;
        case 'q':
            glRotatef(1, 0, 1, 0);
            break;
        case 'e':
            glRotatef(1, 0, -1, 0);
            break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Torus");
    glOrtho(-100, 100, -100, 100, -100, 100);
    glRotatef(60, 1, 0, 0);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(kbin);

    glutMainLoop();
	return 0;
}
