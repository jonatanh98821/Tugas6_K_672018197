#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

void init (void);
void tampil (void);
void mouse (int button, int state, int x, int y);
void ukuran (int, int);
void mouseMotion (int x, int y);
void keyboard (unsigned char, int , int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init (void)
{
	glClearColor (0.0, 0.0, 0.0, 1.0);
	glMatrixMode (GL_PROJECTION);
	glEnable (GL_LIGHTING);
	glEnable (GL_COLOR_MATERIAL);
	glEnable (GL_LIGHT0);
	glEnable (GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode (GL_MODELVIEW);
	glPointSize (5.0f);
	glLineWidth (6.0f);
}

void tampil (void)
{
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else 
		glClear (GL_COLOR_BUFFER_BIT);
		
	glLoadIdentity();
	gluLookAt (0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef (xrot, 1.0f, 0.0f, 0.0f);
	glRotatef (yrot, 1.0f, 1.0f, 0.0f);
	glPushMatrix();
	
	//belakang
	glBegin (GL_QUADS);
	glColor3f(1.0, 1.0, 0.7);
	glVertex3f (-30.0, -20.0, -30.0);
	glVertex3f (-30.0, 20.0, -30.0);
	glVertex3f (30.0, 20.0, -30.0);
	glVertex3f (30.0, -20.0, -30.0);
	glEnd();
	
	//kanan
	glBegin (GL_QUADS);
	glColor3f(0.3, 1.0, 1.5);
	glVertex3f (30.0, 20.0, 10.0);
	glVertex3f (30.0, -20.0, 10.0);
	glVertex3f (30.0, -20.0, -30.0);
	glVertex3f (30.0, 20.0, -30.0);
	glEnd();
	
	//kiri
	glBegin (GL_QUADS);
	glColor3f (1.7, 0.1, 0.6);
	glVertex3f (-30.0, 20.0, 10.0);
	glVertex3f (-30.0, -20.0, 10.0);
	glVertex3f (-30.0, -20.0, -30.0);
	glVertex3f (-30.0, 20.0, -30.0);
	glEnd();

	//bawah
	glBegin (GL_QUADS);
	glColor3f (0.1, 0.0, 0.5);
	glVertex3f (-30.0, -20.0, 10.0);
	glVertex3f (30.0, -20.0, 10.0);
	glVertex3f (30.0, -20.0, -30.0);
	glVertex3f (-30.0, -20.0, -30.0);
	glEnd();
	
	//lemari
	//belakang
	glBegin (GL_QUADS);
	glColor3f (1.0, 1.0, 6.0);
	glVertex3f (0.0, 10.0, -20.0);
	glVertex3f (10.0, 10.0, -20.0);
	glVertex3f (10.0, -15.0, -20.0);
	glVertex3f (0.0, -15.0, -20.0);
	glEnd();
	
	//depan
	glBegin (GL_QUADS);
	glColor3f (1.0, 0.0, 1.0);
	glVertex3f (0.0, 10.0, -10.0);
	glVertex3f (10.0, 10.0, -10.0);
	glVertex3f (10.0, -15.0, -10.0);
	glVertex3f (0.0, -15.0, -10.0);
	glEnd();
	
	//atas
	glBegin (GL_QUADS);
	glColor3f (2.0, 0.5, 1.0);
	glVertex3f (0.0, 10.0, -10.0);
	glVertex3f (10.0, 10.0, -10.0);
	glVertex3f (10.0, 10.0, -20.0);
	glVertex3f (0.0, 10.0, -20.0);
	glEnd();
	
	//kanan
	glBegin (GL_QUADS);
	glColor3f (0.1, 1.0, 2.0);
	glVertex3f (10.0, 10.0, -10.0);
	glVertex3f (10.0, -15.0, -10.0);
	glVertex3f (10.0, -15.0, -20.0);
	glVertex3f (10.0, 10.0, -20.0);
	glEnd();
	
	//bawah
	glBegin (GL_QUADS);
	glColor3f (2.0, 0.5, 1.0);
	glVertex3f (0.0, -15.0, -10.0);
	glVertex3f (10.0, -15.0, -10.0);
	glVertex3f (10.0, -15.0, -20.0);
	glVertex3f (0.0, -15.0, -20.0);
	glEnd();
	
	//kiri
	glBegin (GL_QUADS);
	glColor3f (0.1, 1.0, 2.0);
	glVertex3f (0.0, -15.0, -10.0);
	glVertex3f (0.0, 10.0, -10.0);
	glVertex3f (0.0, 10.0, -20.0);
	glVertex3f (0.0, -15.0, -20.0);
	glEnd();
	
	//garis
	glBegin (GL_LINE_STRIP);
	glColor3f (0.1, 0.1, 0.1);
	glVertex3f (5.0, 10.0, -10.0);
	glVertex3f (5.0, -15.0, -10.0);
	glEnd();
	
	//titik
	glBegin (GL_POINTS);
	glColor3f (0.1, 0.1, 0.1);
	glVertex3f (7.0, -2.0, -10.0);
	glVertex3f (3.0, -2.0, -10.0);
	glEnd();
	
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
	
	
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
			case 'W':
				glTranslatef (0.0, 0.0, 10.0);
				break;
		case 'd':
			case 'D':
				glTranslatef (10.0, 0.0, 0.0);
				break;
		case 's':
			case 'S':
				glTranslatef (0.0, 0.0, -10.0);
				break;
		case 'a':
			case 'A':
				glTranslatef (-10.0, 0.0, 0.0);
				break;
	}
	tampil();
}

//fungsi mouse 1
void idle ()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

//fungsi mouse 2
void mouse (int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;			
	}
	else
	mouseDown = false;
}

//fungsi mouse 3
void mouseMotion (int x, int y)
{
	if (mouseDown)
	{
		xrot = x - ydiff;
		yrot = y + xdiff;
		
		glutPostRedisplay();
	}
}

void ukuran (int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective (50.0, lebar/tinggi,5.0, 500.0);
	glTranslatef (0.0, -5.0, -150.0);
	glMatrixMode (GL_MODELVIEW);
}


int main (int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 600);
	glutInitWindowPosition (250, 80);
	glutCreateWindow ("Jonathan Putera Perdana-672018197");
	init();
	glutDisplayFunc (tampil);
	glutReshapeFunc (ukuran);
	
	glutKeyboardFunc (keyboard);
	
	glutMouseFunc (mouse);
	glutMotionFunc (mouseMotion);
	
	glutIdleFunc (tampil);
	glutMainLoop ();
	return 0;
}
