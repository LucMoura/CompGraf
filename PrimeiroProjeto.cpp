#include <GL/glut.h>

void desenho()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
		glVertex2f(280, 500);
		glVertex2f(400, 400);
		glVertex2f(200, 400);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
		glVertex2f(180, 350); 
		glVertex2f(460, 350); 
		glVertex2f(400, 250); 
		glVertex2f(240, 250); 
	glEnd();
	glColor3f(0.6, 0.3, 0.0);
	glLineWidth(10.0);
	glBegin(GL_LINES);
		glVertex2f(280, 350); 
		glVertex2f(280, 500); 
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
		glVertex2f(280, 500);
		glVertex2f(300, 500);
		glVertex2f(280, 490);
		glVertex2f(300, 490);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(200,300);
	glutCreateWindow("Aula1");
	glutDisplayFunc(desenho);
	gluOrtho2D(0, 640, 0, 640);
	glClearColor(0.96, 0.87, 0.70, 0);
	glutMainLoop();
	return 0;
}
