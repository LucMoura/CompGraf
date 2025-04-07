#include <GL/glut.h>

float y_offset = 0.0f;

void desenhaQuadrado() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(0.0f, y_offset, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(280, 280);
    glVertex2f(360, 280);
    glVertex2f(360, 360);
    glVertex2f(280, 360);
    glEnd();

    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y) {
    if (tecla == 32) {
        y_offset += 10.0f;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Quadrado Vermelho com Translação Y");

    gluOrtho2D(0, 640, 0, 640);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutDisplayFunc(desenhaQuadrado);
    glutKeyboardFunc(teclado);

    glutMainLoop();
    return 0;
}
