//#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "OBJModel.h"
/* Global variables */

char title[] = "3D Shapes";
// drawing mode
GLint polyMode = GL_FILL;

// the shape to be drawn
std::string shape = "Cube";
// custom model
OBJModel model;

// translation and rotation values
GLfloat translate_x = 0.0f;
GLfloat translate_y = 0.0f;
GLfloat translate_z = 0.0f;
GLfloat rotation_x = 0.0f;
GLfloat rotation_y = 0.0f;
GLfloat transAmount = .5f;
GLfloat rotAmount = 5.0f;
GLfloat red = 0.5f;
GLfloat green = 0.5f;
GLfloat blue = 0.5f;

// struct to hold the rgb values of a color
struct Color
{
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};

// our possible colors
Color color[] = {
{ 1.0f, 0.0f, 0.0f }, //red
{ 0.0f, 1.0f, 0.0f }, //green
{ 0.0f, 0.0f, 1.0f }, //blue
{ 1.0f, 1.0f, 0.0f }, //yellow
{ 1.0f, 0.0f, 1.0f }, //purple
{ 0.0f, 1.0f, 1.0f }, //teal
{ 1.0f, 1.0f, 1.0f }, //white
{ 0.5f, 0.5f, 0.5f }  //grey
};

int colorSize = sizeof(color) / sizeof(color[0]);
int colorIndex = 0;
/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void displayCube()
{
    glTranslatef(translate_x, translate_y, translate_z);
    //glColor3f(1.0f, 0.0f, 0.0f);
    glColor3f(red, green, blue);
    glutSolidCube(1.0);
    //glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
    //   // Top face (y = 1.0f)
    //   // Define vertices in counter-clockwise (CCW) order with normal pointing out
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(1.0f, 1.0f, 1.0f);

    //// Bottom face (y = -1.0f)
    //glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    //glVertex3f(1.0f, -1.0f, 1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(1.0f, -1.0f, -1.0f);

    //// Front face  (z = 1.0f)
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    //glVertex3f(1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);

    //// Back face (z = -1.0f)
    //glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    //glVertex3f(1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(1.0f, 1.0f, -1.0f);

    //// Left face (x = -1.0f)
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    //glVertex3f(-1.0f, 1.0f, 1.0f);
    //glVertex3f(-1.0f, 1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, -1.0f);
    //glVertex3f(-1.0f, -1.0f, 1.0f);

    //// Right face (x = 1.0f)
    //glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    //glVertex3f(1.0f, 1.0f, -1.0f);
    //glVertex3f(1.0f, 1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, 1.0f);
    //glVertex3f(1.0f, -1.0f, -1.0f);
    //glEnd();  // End of drawing color-cube

}

void displayPyramid()
{
    glTranslatef(translate_x, translate_y, translate_z);
    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
       // Front
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glColor3f(red, green, blue);
    glVertex3f(0.0f, 1.0f, 0.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(1.0f, -1.0f, 1.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back
    //glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(1.0f, -1.0f, -1.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left
    //glColor3f(1.0f, 0.0f, 0.0f);       // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    //glColor3f(0.0f, 0.0f, 1.0f);       // Blue
    glVertex3f(-1.0f, -1.0f, -1.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);       // Green
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();   // Done drawing the pyramid
}

void displaySphere()
{
    glTranslatef(translate_x, translate_y, translate_z);
    //glColor3f(0.9, 0.3, 0.2);
    glColor3f(red, green, blue);
    glutSolidSphere(1.0, 50, 50);
}

void displayOther()
{
    glTranslatef(translate_x, translate_y, translate_z);
    //glColor3f(red, green, blue);
    model.draw(red, green, blue);
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glPolygonMode(GL_FRONT_AND_BACK, polyMode);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   
    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(0.0f, 0.0f, -7.0f);  
    gluLookAt(
        0.0f, 0.0f, 3.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f);

    glRotatef(rotation_x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation_y, 0.0f, 1.0f, 0.0f);

    if (shape == "Cube")
    {
        //glPolygonMode(GL_FRONT_AND_BACK, polyMode);
        displayCube();
    }
    else if (shape == "Pyramid")
    {
        //glPolygonMode(GL_FRONT_AND_BACK, polyMode);
        displayPyramid();
    }
    else if (shape == "Sphere")
    {
        displaySphere();
    }
    else if (shape == "other")
    {
        displayOther();
    }
    

    // Render a pyramid consists of 4 triangles
    //glLoadIdentity();                  // Reset the model-view matrix
    //glTranslatef(1.5f, 0.0f, 6.0f);
    //glRotatef(90, -1.5f, 0.0f, -6.0f);
    //glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen

    

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void specialKeys(int key, int x, int y)
{
    // UP ARROW
    if (key == GLUT_KEY_UP)
    {
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        rotation_x += rotAmount;
    }
    // DOWN ARROW
    if (key == GLUT_KEY_DOWN)
    {
        rotation_x -= rotAmount;
    }
    // LEFT ARROW
    if (key == GLUT_KEY_LEFT)
    {
        rotation_y += rotAmount;
    }
    // RIGHT ARROW
    if (key == GLUT_KEY_RIGHT)
    {
        rotation_y -= rotAmount;
    }
}

void normalKeys(unsigned char key, int x, int y)
{
    // ESCAPE
    if (key == 27)
    {
        exit(0);
    }
    if (key == 'z')
    {
        if (polyMode == GL_FILL)
        {
            polyMode = GL_LINE;
        }
        else
        {
            polyMode = GL_FILL;
        }
    }
    if (key == 'w')
    {
        translate_z += transAmount;
    }
    if (key == 's')
    {
        translate_z -= transAmount;
    }
    if (key == 'a')
    {
        translate_x -= transAmount;
    }
    if (key == 'd')
    {
        translate_x += transAmount;
    }
    if (key == 'q')
    {
        translate_y += transAmount;
        
    }
    if (key == 'e')
    {
        translate_y -= transAmount;
       
    }
    if (key == 'c')
    {
        red = color[colorIndex].red;
        green = color[colorIndex].green;
        blue = color[colorIndex].blue;
        colorIndex = (colorIndex + 1) % colorSize;
    }
    // ONE
    if (key == '1')
    {
        translate_x = 0.0f;
        translate_y = 0.0f;
        translate_z = 0.0f;
        rotation_x = 0.0f;
        rotation_y = 0.0f;
        red = 1.0f;
        green = 1.0f;
        blue = 1.0f;

        shape = "Cube";
    }
    // TWO
    if (key == '2')
    {
        translate_x = 0.0f;
        translate_y = 0.0f;
        translate_z = 0.0f;
        rotation_x = 0.0f;
        rotation_y = 0.0f;
        red = 1.0f;
        green = 1.0f;
        blue = 1.0f;

        shape = "Pyramid";
    }
    if (key == '3')
    {
        translate_x = 0.0f;
        translate_y = 0.0f;
        translate_z = 0.0f;
        rotation_x = 0.0f;
        rotation_y = 0.0f;
        red = 1.0f;
        green = 1.0f;
        blue = 1.0f;

        shape = "Sphere";
    }
    if (key == '4')
    {
        translate_x = 0.0f;
        translate_y = 0.0f;
        translate_z = 0.0f;
        rotation_x = 0.0f;
        rotation_y = 0.0f;
        red = 1.0f;
        green = 1.0f;
        blue = 1.0f;

        shape = "other";
    }
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    
    //model.readfile("cube.obj");
    //model.readfile("Human.obj");
    //model.readfile("M9.obj");
    //model.readfile("TieOBJ.obj");
    model.readfile("alienbest2.obj"); // doesn't work quite right because it is quads not triangles
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title



    void (*displayFunc)() = &display;
    glutDisplayFunc(displayFunc);       // Register callback handler for window re-paint event
    glutIdleFunc(displayFunc);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(normalKeys);
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
