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

//vertices for base
float ver[][3] =
{
    {-1.25,-1.25,0.10},
    {-1.25,1.25,0.10},
    {1.25,1.25,0.10},
    {1.25,-1.25,0.10},
    {-1.25,-1.25,-0.10},
    {-1.25,1.25,-0.10},
    {1.25,1.25,-0.10},
    {1.25,-1.25,-0.10},
};

//vertices for bigger cube
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

//vertices for inner cube
float ver2[][3] =
{
    {-0.45,-0.45,1.4},
    {-0.45,0.45,1.4},
    {0.45,0.45,1.4},
    {0.45,-0.45,1.4},
    {-0.45,-0.45,0.4},
    {-0.45,0.45,0.4},
    {0.45,0.45,0.4},
    {0.45,-0.45,0.4},
};

//vertices for door
float ver3[][3]=
{
    {-0.15,-0.76,0.5},
    {-0.15,0.76,0.5},
    {0.15,0.76,0.5},
    {0.15,-0.76,0.5},
    {-0.15,-0.76,0.0},
    {-0.15,0.76,0.0},
    {0.15,0.76,0.0},
    {0.15,-0.76,0.0},

};

//vertices for door arch
float ver8[][3]=
{
    {-0.15,-0.76,0.6},
    {-0.15,0.76,0.6},
    {0.15,0.76,0.6},
    {0.15,-0.76,0.6},
    {-0.15,-0.76,0.5},
    {-0.15,0.76,0.5},
    {0.15,0.76,0.5},
    {0.15,-0.76,0.5},
    
};

//vertices for left window
float ver4[][3]=
{
    {-0.6,-0.76,0.9},
    {-0.6,0.76,0.9},
    {-0.45,0.76,0.9},
    {-0.45,-0.76,0.9},
    {-0.6,-0.76,0.7},
    {-0.6,0.76,0.7},
    {-0.45,0.76,0.7},
    {-0.45,-0.76,0.7},
};

//vertices for right window
float ver5[][3]=
{
    {0.6,-0.76,0.9},
    {0.6,0.76,0.9},
    {0.45,0.76,0.9},
    {0.45,-0.76,0.9},
    {0.6,-0.76,0.7},
    {0.6,0.76,0.7},
    {0.45,0.76,0.7},
    {0.45,-0.76,0.7},
};

//vertices for left window number 2
float ver6[][3]=
{
    {-0.35,-0.76,0.9},
    {-0.35,0.76,0.9},
    {-0.2,0.76,0.9},
    {-0.2,-0.76,0.9},
    {-0.35,-0.76,0.7},
    {-0.35,0.76,0.7},
    {-0.2,0.76,0.7},
    {-0.2,-0.76,0.7},
};

//vertices for right window number 2
float ver7[][3]=
{
    {0.35,-0.76,0.9},
    {0.35,0.76,0.9},
    {0.2,0.76,0.9},
    {0.2,-0.76,0.9},
    {0.35,-0.76,0.7},
    {0.35,0.76,0.7},
    {0.2,0.76,0.7},
    {0.2,-0.76,0.7},
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
    
    //door arch
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3fv(ver8[a]);
    glVertex3fv(ver8[b]);
    glVertex3fv(ver8[c]);
    glVertex3fv(ver8[d]);
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
    
    glFlush();
    glutSwapBuffers();
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
        glOrtho(-30.0, 30.0, -30.0 * (GLfloat) h / (GLfloat) w, 30.0 * (GLfloat) h / (GLfloat) w, -30.0, 30.0);
    else
        glOrtho(-30.0 * (GLfloat) w / (GLfloat) h, 30.0 * (GLfloat) w / (GLfloat) h, -30.0, 30.0, -30.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv); //set window properties
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Project 1: Taj Mahal");
    glutDisplayFunc(mydisplay); //display callback
    glutSpecialFunc(specialKeys);
    init(); //set OpenGL state
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();//enter event loop
}




