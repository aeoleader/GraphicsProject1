//rotate using the left and the right arrow
//wireframe - 'w'
//filled - 'f'

/* Activity.cpp
 
 September 14th, 2007*/

/* Starter file for in class activity
 
 */
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>

static double rotate_x = 0;
GLuint towersDLid;

//vertices for base
//@Nan: I changed the values from 1.25 to 1.50 to make the base bigger.
float ver[][3] =
{
    {-1.50,-1.50,0.10},
    {-1.50,1.50,0.10},
    {1.50,1.50,0.10},
    {1.50,-1.50,0.10},
    {-1.50,-1.50,-0.10},
    {-1.50,1.50,-0.10},
    {1.50,1.50,-0.10},
    {1.50,-1.50,-0.10},
};

//vertices for bigger cube
float ver1[][3] =
{
    {-0.95,-0.95,1.3},
    {-0.95,0.95,1.3},
    {0.95,0.95,1.3},
    {0.95,-0.95,1.3},
    {-0.95,-0.95,0.10},
    {-0.95,0.95,0.10},
    {0.95,0.95,0.10},
    {0.95,-0.95,0.10},
};

//vertices for inner cube
float ver2[][3] =
{
    {-0.6,-0.6,1.45},
    {-0.6,0.6,1.45},
    {0.6,0.6,1.45},
    {0.6,-0.6,1.45},
    {-0.6,-0.6,0.4},
    {-0.6,0.6,0.4},
    {0.6,0.6,0.4},
    {0.6,-0.6,0.4},
};

//vertices for door
float ver3[][3]=
{
    {-0.18,-0.96,0.7},
    {-0.18,0.96,0.7},
    {0.18,0.96,0.7},
    {0.18,-0.96,0.7},
    {-0.18,-0.96,0.0},
    {-0.18,0.96,0.0},
    {0.18,0.96,0.0},
    {0.18,-0.96,0.0},
    
};

//vertices for left window
float ver4[][3]=
{
    {-0.5,-0.96,0.9},
    {-0.5,0.96,0.9},
    {-0.3,0.96,0.9},
    {-0.3,-0.96,0.9},
    {-0.5,-0.96,0.65},
    {-0.5,0.96,0.65},
    {-0.3,0.96,0.65},
    {-0.3,-0.96,0.65},
};

//vertices for right window
float ver5[][3]=
{
    {0.5,-0.96,0.9},
    {0.5,0.96,0.9},
    {0.3,0.96,0.9},
    {0.3,-0.96,0.9},
    {0.5,-0.96,0.65},
    {0.5,0.96,0.65},
    {0.3,0.96,0.65},
    {0.3,-0.96,0.65},
};

//vertices for left window number 2
float ver6[][3]=
{
    {-0.5,-0.96,0.55},
    {-0.5,0.96,0.55},
    {-0.3,0.96,0.55},
    {-0.3,-0.96,0.55},
    {-0.5,-0.96,0.3},
    {-0.5,0.96,0.3},
    {-0.3,0.96,0.3},
    {-0.3,-0.96,0.3},
};

//vertices for right window number 2
float ver7[][3]=
{
    {0.5,-0.96,0.55},
    {0.5,0.96,0.55},
    {0.3,0.96,0.55},
    {0.3,-0.96,0.55},
    {0.5,-0.96,0.3},
    {0.5,0.96,0.3},
    {0.3,0.96,0.3},
    {0.3,-0.96,0.3},
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

//Code segment to draw a single tower
void drawTower()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    GLUquadricObj *qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL); /* flat shaded */
    gluQuadricNormals(qobj, GLU_FLAT);
    //@para: base radius/top radius/height/slices/stacks
    gluCylinder(qobj, 0.25, 0.10, 2.25, 100, 5);
    
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.75);
    gluDisk(qobj, 0.20, 0.30, 100, 5);
    
    glTranslatef(0.0, 0.0, 0.75);
    gluDisk(qobj, 0.13, 0.23, 100, 5);
    
    glTranslatef(0.0, 0.0, 0.75);
    gluDisk(qobj, 0.0, 0.15, 100, 5);
    
    /*** Draw little cylinder ***/
    gluCylinder(qobj, 0.10, 0.10, 0.15, 20, 5);
    
    glTranslatef(0.0, 0.0, 0.15);
    gluDisk(qobj, 0.0, 0.15, 50, 5);
    
    /*** Draw the big sphere ***/
    gluSphere(qobj, 0.10, 15, 20);
    
    glTranslatef(0.0, 0.0, 0.10);
    gluCylinder(qobj, 0.01, 0.01, 0.15, 20, 5);
    
    /*** Draw little spheres on the top ***/
    glTranslatef(0.0, 0.0, 0.05);
    gluSphere(qobj, 0.025, 15, 20);
    
    glTranslatef(0.0, 0.0, 0.05);
    gluSphere(qobj, 0.02, 15, 20);
    
    glTranslatef(0.0, 0.0, 0.05);
    gluSphere(qobj, 0.015, 15, 20);
    glPopMatrix();
}

GLuint createDL() {
    GLuint towerDL,loopDL;
    
    towerDL = glGenLists(1); //generate the id for the snowman displaylist
    loopDL = glGenLists(2); //generate the id for the loop display list
    
    glNewList(towerDL, GL_COMPILE);
    drawTower();
    glEndList();
    
    //generate the list
    glNewList(loopDL, GL_COMPILE);
    
    /* @Nan: Don't know why it doesn't work
     for(int i = -1.25; i < 1.25; i+=2.5)
     {
     glPushMatrix();
     glTranslatef(i, 1.25, 0.1);
     glCallList(towerDL);
     glPopMatrix();
     
     glPushMatrix();
     glTranslatef(i, -1.25, 0.1);
     glCallList(towerDL);
     glPopMatrix();
     }
     */
    
    glPushMatrix();
    glTranslatef(-1.25, -1.25, 0.1);
    glCallList(towerDL);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1.25, 1.25, 0.1);
    glCallList(towerDL);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.25, -1.25, 0.1);
    glCallList(towerDL);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.25, 1.25, 0.1);
    glCallList(towerDL);
    glPopMatrix();
    
    glEndList();
    return(loopDL);
}

//Draw body of the Taj
void quad(int a,int b,int c,int d)
{
    //bigger base
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glNormal3f(0, 0, 1);
    glVertex3fv(ver[a]);
    glColor3fv(color[b]);
    glNormal3f(1, 0, 1);
    glVertex3fv(ver[b]);
    glColor3fv(color[c]);
    glNormal3f(0, 1, 0);
    glVertex3fv(ver[c]);
    glColor3fv(color[d]);
    glNormal3f(0, 0, 1);
    glVertex3fv(ver[d]);
    glEnd();
    
    //main body (cube)
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glNormal3f(0, 0, 1);
    glVertex3fv(ver1[a]);
    glColor3fv(color[b]);
    glNormal3f(1, 0, 1);
    glVertex3fv(ver1[b]);
    glColor3fv(color[c]);
    glNormal3f(0, 1, 0);
    glVertex3fv(ver1[c]);
    glColor3fv(color[d]);
    glNormal3f(0, 0, 1);
    glVertex3fv(ver1[d]);
    glEnd();
    
    //upper extension of the main body
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glNormal3f(0, 0, 1);
    glVertex3fv(ver2[a]);
    glColor3fv(color[b]);
    glNormal3f(1, 0, 1);
    glVertex3fv(ver2[b]);
    glColor3fv(color[c]);
    glNormal3f(0, 1, 0);
    glVertex3fv(ver2[c]);
    glColor3fv(color[d]);
    glNormal3f(0, 0, 1);
    glVertex3fv(ver2[d]);
    glEnd();
    
    //door
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3fv(ver3[a]);
    glVertex3fv(ver3[b]);
    glVertex3fv(ver3[c]);
    glVertex3fv(ver3[d]);
    glEnd();
    
    //left window
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3fv(ver4[a]);
    glVertex3fv(ver4[b]);
    glVertex3fv(ver4[c]);
    glVertex3fv(ver4[d]);
    glEnd();
    
    //right window
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3fv(ver5[a]);
    glVertex3fv(ver5[b]);
    glVertex3fv(ver5[c]);
    glVertex3fv(ver5[d]);
    glEnd();
    
    //second left window
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3fv(ver6[a]);
    glVertex3fv(ver6[b]);
    glVertex3fv(ver6[c]);
    glVertex3fv(ver6[d]);
    glEnd();
    
    //second right window
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3fv(ver7[a]);
    glVertex3fv(ver7[b]);
    glVertex3fv(ver7[c]);
    glVertex3fv(ver7[d]);
    glEnd();
    
}

void ColorBody()
{
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);
    
}

// Initialize OpenGL graphics
void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0); // clear the viewport to black
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float lightColor[4]= {1, 1, 1, 1};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glEnable(GL_COLOR_MATERIAL);
    
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    
    glMatrixMode(GL_MODELVIEW);
    
    
}


void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_x -= 5.0;
    else if (key == GLUT_KEY_LEFT)
        rotate_x -= -5.0;
    
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
    
    glRotatef( rotate_x, 0.0, 0.0, 1.0 );
    ColorBody();
    towersDLid = createDL();
    glCallList(towersDLid);
    glFlush();
    //glutSwapBuffers();
}

// keyboard callback function that exits the application when "q" is pressed
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w':
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            mydisplay();
            break;
        case 'f':
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            mydisplay();
            break;
        case 27:
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
        glOrtho(-40.0, 40.0, -40.0 * (GLfloat) h / (GLfloat) w, 40.0 * (GLfloat) h / (GLfloat) w, -40.0, 40.0);
    else
        glOrtho(-40.0 * (GLfloat) w / (GLfloat) h, 40.0 * (GLfloat) w / (GLfloat) h, -40.0, 40.0, -40.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv); //set window properties
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Project 1: Taj Mahal");
    glutDisplayFunc(mydisplay); //display callback
    glutSpecialFunc(specialKeys);
    init(); //set OpenGL state
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();//enter event loop
}


