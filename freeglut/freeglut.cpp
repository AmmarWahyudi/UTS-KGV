#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>
#include <time.h>

//Deklarasi Variable

float red = 1.0f, blue = 1.0f, green = 1.0f;
float z_pos = 0.0f;
float rot = 0.0f;

//Membuat Method
void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0f, z_pos);
    glColor3ub(rand() % 255, rand() % 255, rand() % 255);
    glBegin(GL_POLYGON);
    
    glVertex3f(-0.5, -0.5, -5);
    
    glVertex3f(-0.75, 0, -5);
    
    glVertex3f(-0.5, 0.5, -5);
    
    glVertex3f(0, 0.75, -5);

    glVertex3f(0.5, 0.5, -5);
   
    glVertex3f(0.75, 0, -5);
 
    glVertex3f(0.5, -0.5, -5);
   
    glVertex3f(0, -0.75, -5);
    glEnd();
    glFlush();
    glutSwapBuffers();
}

//Membuat Method init
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (GLdouble)500.0 / (GLdouble)500.0, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}
//Membuat Method resize
void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (GLdouble)w / (GLdouble)h, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}
//Membuat Method timeout
void myTimeOut(int id)
{
    rot += 10;
    glutPostRedisplay(); 
    glutTimerFunc(100, myTimeOut, 0); 
}

//Membuat Method keyboard
    void myKeyboard(unsigned char key, int x, int y)
    {
    if ((key == 'w') || (key == ',')) z_pos -= 0.1f;
    if ((key == 's') || (key == '.')) z_pos += 0.1f;
}
    void myNew(unsigned char key, int x, int y, int z)
    {
        if ((key == 'x') || (key == '1')) red -= 0.1f;
        if ((key == 'd') || (key == '2')) blue += 0.1f;
        if ((key == 'a') || (key == '3')) green /= 0.1f;
    }

//Program Utama
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("simple");
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(100, myTimeOut, 0);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
}
