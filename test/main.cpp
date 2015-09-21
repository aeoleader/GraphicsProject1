/* Activity.cpp
 
 September 14th, 2007*/

/* Starter file for in class activity
 
 */
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>

//vertices for base
float ver[][3] =
{
    {-1.75,-1.75,0.10},
    {-1.75,1.75,0.10},
    {1.75,1.75,0.10},
    {1.75,-1.75,0.10},
    {-1.75,-1.75,-0.10},
    {-1.75,1.75,-0.10},
    {1.75,1.75,-0.10},
    {1.75,-1.75,-0.10},
};

//vertices for cube
float ver1[][3] =
{
    {-0.75,-0.75,1.10},
    {-0.75,0.75,1.10},
    {0.75,0.75,1.10},
    {0.75,-0.75,1.10},
    {-0.75,-0.75,0.10},
    {-0.75,0.75,0.10},
    {0.75,0.75,0.10},
    {0.75,-0.75,0.10},
};

GLfloat color[][3] =
{
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
    {0.973, 0.973, 1.000},
};


void drawTower()
{
    GLUquadricObj *qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
    gluQuadricNormals(qobj, GLU_FLAT);
    //para: base radius/top radius/height/slices/stacks
    gluCylinder(qobj, 0.35, 0.13, 2.25, 100, 5);
    
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.75);
    gluDisk(qobj, 0.28, 0.38, 100, 5);
    
    glTranslatef(0.0, 0.0, 0.75);
    gluDisk(qobj, 0.18, 0.28, 100, 5);
    
    glTranslatef(0.0, 0.0, 0.75);
    gluDisk(qobj, 0.0, 0.20, 100, 5);
    
    //para: base radius/top radius/height/slices/stacks
    gluCylinder(qobj, 0.12, 0.12, 0.15, 20, 5);
    glPopMatrix();
}

void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);
    
    glColor3fv(color[b]);
    glVertex3fv(ver[b]);
    
    glColor3fv(color[c]);
    glVertex3fv(ver[c]);
    
    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver1[a]);
    
    glColor3fv(color[b]);
    glVertex3fv(ver1[b]);
    
    glColor3fv(color[c]);
    glVertex3fv(ver1[c]);
    
    glColor3fv(color[d]);
    glVertex3fv(ver1[d]);
    glEnd();
}

void colorcube()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
}

// Initialize OpenGL graphics
void init()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glClearColor (0.0, 0.0, 0.0, 1.0); // clear the viewport to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glMatrixMode(GL_MODELVIEW);
    
}

double rotate_y = 0;
double rotate_x = 0;
void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();
}

void mydisplay(void)
{
    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 60, w / h, 0.1, 100 );
    
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    
    gluLookAt
    (
     3, 3, 3,
     0, 0, 0,
     0, 0, 1
     );
    
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    colorcube();
    glTranslatef(1.25, 1.25, 0.0);
    drawTower();
    
    glutSwapBuffers();
}

// keyboard callback function that exits the application when "q" is pressed
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:  /*  Escape Key  */
            exit(0);
            break;
    }
}

// reshape function
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h / (GLfloat) w, 10.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-10.0 * (GLfloat) w / (GLfloat) h, 10.0 * (GLfloat) w / (GLfloat) h, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv); //set window properties
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Project 1: Taj Mahal");
    glutDisplayFunc(mydisplay); //display callback
    glutSpecialFunc( specialKeys );
    init(); //set OpenGL state
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
    
    glutMainLoop();//enter event loop
}

