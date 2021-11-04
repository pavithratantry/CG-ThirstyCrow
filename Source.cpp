#include <windows.h>
#include <glut.h>
#include<iostream>

# define PI 3.1416

GLfloat position = -1.2f, xpos = -1.0f, ypos = 0.45f, yup, ydown, speed = 0.08f, crowspeed = 0.1f;

int  dsix = 0, waterflag = 0, pebbleflag = 0, stonereturnflag = 0, flyaway = 0;

void Display1();
void Display2();
void Display3();
void Display4();
void Display5();
void Display6();
void Display7();
void Display8();

void move(int value) {

    if (position > 1.3)     //continuous display 
    {
        position = -1.2f;
    }

    position += speed;     //movement of crow

    if (!waterflag)       //display5
    {
        xpos += crowspeed;
        ypos -= crowspeed;
    }
    if (stonereturnflag) //display6
    {
        xpos += crowspeed;
        yup += crowspeed;
    }
    ydown -= speed;
    glutPostRedisplay();

    glutTimerFunc(100, move, 0);
}

void output(GLfloat x, GLfloat y, const char* text)
{
    const char* p;
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScaled(0.035, 0.035, 0);
    for (p = text; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void output1(GLfloat x, GLfloat y, const char* text)
{
    const char* p;
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScaled(0.0005, 0.0005, 0);
    for (p = text; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void StartingText()
{
    glColor3f(1.0, 1.0, 1.0);
    output(-40.0, 50.0, "GLOBAL ACADEMY OF TECHNOLOGY");
    output(-20.0, 40.0, "DEPT OF CSE");
    output(-30, 25.0, "NAME: PAVITHRA K TANTRY");
    output(-30.0, 15.0, "USN: 1GA18CS189");
    output(-60.0, 5.0, "PROJECT: SIMULATION OF STORY THIRSTY CROW");
    output(-45.0, -5.0, "UNDER THE GUIDANCE OF: MRS. RESHMA S");
    output(-55.0, -40.0, "TO SEE THE STORY PRESS 1, 2, 3, 4, 5, 6, 7, 8");
    glFlush();
}

void circle(GLfloat x, GLfloat y, GLfloat radius, GLfloat colorx, GLfloat colory, GLfloat colorz)
{
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(colorx, colory, colorz);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void sun()
{
    circle(-.7f, .8f, .10f, 1.0, .25, 0.0);
}

void Pebble()
{
    circle(0.6f, 0.0f, 0.02f, 0.2f, 0.2f, 0.2f);
}

void Bird()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);

    glVertex2f(-0.5, 0.15);
    glVertex2f(-0.3, 0.25);
    glVertex2f(-0.1, 0.15);
    glVertex2f(-0.3, 0.09);

    glEnd();

    //WING ONE

    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.2);
    glVertex2f(-0.4, 0.25);
    glVertex2f(-0.25, 0.35);
    glVertex2f(-0.3, 0.28);
    glVertex2f(-0.35, 0.2);
    glEnd();

    //WING TWO

    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.20);
    glVertex2f(-0.2, 0.31);
    glVertex2f(-0.1, 0.22);

    glEnd();

    //BEAK

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.55, 0.1);
    glVertex2f(-0.49, 0.15);
    glVertex2f(-0.55, 0.1);
    glVertex2f(-0.48, 0.14);
    glVertex2f(-0.48, 0.14);
    glVertex2f(-0.5, 0.1);
    glVertex2f(-0.5, 0.1);
    glVertex2f(-0.45, 0.15);
    glEnd();

    //EYE

    glPointSize(25.0);
    glTranslatef(-0.45f, 0.18f, 0);
    glBegin(GL_POINTS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.0f, -0.0f);
    glEnd();

    glPointSize(5.0);
    glTranslatef(-0.01f, 0.0f, 0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.0f, -0.0f);
    glEnd();

    if (pebbleflag)
    {
        circle(-0.075f, -0.075f, 0.02f, 0.2f, 0.2f, 0.2f);
    }
}

void mountain()
{
    glColor3f(0.1f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.93, 0.1);
    glVertex2f(-0.0, 0.5);
    glVertex2f(0.93, 0.1);
    glEnd();

}

void sky()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4f, 0.7f, 0.9f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(-1.0f, 0.1f);
    glEnd();
}

void pot()
{
    int triangleAmount = 20;
    GLfloat k = .4f; GLfloat l = -.7f;
    GLfloat radius = .13f;

    GLfloat Pi = PI;
    circle(0.4f, -0.7f, 0.13f, 0.439216f, 0.858824f, 0.576471f);

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.558824f, 0.558824f, 0.558824f);
    glVertex2f(k, l); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            k + (radius * cos(i * Pi / triangleAmount)),
            l + (radius * sin(i * Pi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.558824f, 0.558824f, 0.558824f);
    glVertex2f(0.47f, -0.65f);
    glVertex2f(0.32f, -0.65f);
    glVertex2f(0.32f, -0.55f);
    glVertex2f(0.47f, -0.55f);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(0.47f, -0.55f);
    glVertex2f(0.32f, -0.55f);
    glVertex2f(0.30f, -0.52f);
    glVertex2f(0.50f, -0.52f);

    glEnd();

}

void waterdrop()
{
    glBegin(GL_POLYGON);
    glColor3f(0.439216f, 0.858824f, 0.576471f);
    glVertex2f(0.16f, -0.72f);
    glVertex2f(0.11f, -0.70f);
    glVertex2f(.08f, -0.67f);
    glVertex2f(0.11f, -0.64f);
    glVertex2f(0.13f, -0.64f);
    glVertex2f(0.15f, -0.67f);
    glVertex2f(0.16f, -0.70f);
    glVertex2f(0.17f, -0.72f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.439216f, 0.858824f, 0.576471f);
    glVertex2f(0.20f, -0.62f);
    glVertex2f(0.11f, -0.60f);
    glVertex2f(.08f, -0.57f);
    glVertex2f(0.11f, -0.54f);
    glVertex2f(0.16f, -0.54f);
    glVertex2f(0.18f, -0.57f);
    glVertex2f(0.18f, -0.60f);
    glEnd();

    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3f(0.439216f, 0.858824f, 0.576471f);
    glVertex2f(0.47f, -0.58f);
    glVertex2f(0.32f, -0.58f);
    glVertex2f(0.32f, -0.55f);
    glVertex2f(0.47f, -0.55f);

    glEnd();

    circle(0.4f, -0.7f, 0.13f, 0.439216f, 0.858824f, 0.576471f);

}

void stone()
{
    circle(-.7f, -.7f, .02f, 0.2f, 0.2f, 0.2f);
    circle(-.67f, -.75f, .02f, 0.2f, 0.2f, 0.2f);
    circle(-.67f, -.67f, .02f, 0.2f, 0.2f, 0.2f);
    circle(-.63f, -.7f, .02f, 0.2f, 0.2f, 0.2f);
    circle(-.66f, -.70f, .02f, 0.2f, 0.2f, 0.2f);
}

void grass()
{
    glBegin(GL_POLYGON);
    glColor4f(0.0, 1.0, 0.0, 1.0);
    glVertex2f(-1.0f, 0.1f);
    glVertex2f(1.0f, 0.1f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();
}

void cloud1()
{
    circle(.5f, .8f, .05f, 1.0, 1.0, 1.0);
    circle(.55f, .78f, .05f, 1.0, 1.0, 1.0);
    circle(.45f, .78f, .05f, 1.0, 1.0, 1.0);
    circle(.52f, .75f, .05f, 1.0, 1.0, 1.0);
    circle(.6f, .77f, .05f, 1.0, 1.0, 1.0);
    glFlush();
}

void cloud2()
{
    circle(-.5f, .8f, .05f, 1.0, 1.0, 1.0);
    circle(-.55f, .78f, .05f, 1.0, 1.0, 1.0);
    circle(-.45f, .78f, .05f, 1.0, 1.0, 1.0);
    circle(-.52f, .75f, .05f, 1.0, 1.0, 1.0);
    circle(-.6f, .77f, .05f, 1.0, 1.0, 1.0);
    glFlush();
}

void tree()
{
    glBegin(GL_POLYGON);
    glColor3ub(83, 53, 10);
    glVertex2f(-0.62f, -0.24f);
    glVertex2f(-0.58f, -0.24f);
    glVertex2f(-0.58f, -0.8f);
    glVertex2f(-0.62f, -0.8f);
    glEnd();

    circle(-.67f, -.11f, .15f, 0.0, 0.3, 0.0);
    circle(-.7f, .1f, .15f, 0.0, 0.3, 0.0);
    circle(-.59f, .23f, .15f, 0.0, 0.3, 0.0);
    circle(-.5f, .05f, .18f, 0.0, 0.3, 0.0);
    circle(-.53f, -.12f, .15f, 0.0, 0.3, 0.0);

}

void reshape(int w, int h)
{
    float aspectRatio = (float)w / (float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(145, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //Set background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -20);
    StartingText();
    glFlush();
}

void Display1()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    grass();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-0.75, -0.9, "Once, it was a hot sunny day...");

    glLoadIdentity();
    glTranslatef(0.0, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(0.6, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(1.2, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(-0.15, 0.0, 0.0);
    sun();
    glLoadIdentity();
    glFlush();
}

void Display2()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    grass();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-0.75, -0.9, "A crow was very thirsty..");

    glLoadIdentity();
    glTranslatef(0.0, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(1.2, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(-0.17, 0.0, 0.0);
    sun();
    glTranslatef(position, 0.4f, 0.0f);
    glRotatef(180, 0, 1, 0);
    Bird();
    glLoadIdentity();
    glFlush();

}

void Display3()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    grass();
    mountain();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-0.75, -0.9, "It looked for water here and there..");

    glLoadIdentity();
    glTranslatef(0.0, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(-0.17, 0.0, 0.0);
    sun();

    glTranslatef(position, 0.4f, 0.0f);
    glRotatef(180, 0, 1, 0);
    Bird();
    glLoadIdentity();
    glFlush();

}

void Display4()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    grass();
    pot();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-0.75, -0.9, "At last it found a pot...");
    glLoadIdentity();
    glTranslatef(1.5, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(-0.17, 0.0, 0.0);
    sun();
    glLoadIdentity();
    stone();
   
    glPushMatrix();
    glTranslatef(-1.0, 0.45f, 0.0f);
    glRotatef(180, 0, 1, 0);
    Bird();
    glPopMatrix();

    glFlush();


}

void Display5()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    grass();
    pot();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-0.85, -0.9, "But there was very little water & it couldn't reach...");
    glLoadIdentity();
    glTranslatef(1.5, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(-0.17, 0.0, 0.0);
    sun();
    glLoadIdentity();
    stone();

    glPushMatrix();
    glTranslatef(xpos, ypos, 0.0f);
    if (xpos >= -0.2f && ypos <= -0.55f)
    {
        waterflag = 1;
    }
    glRotatef(180, 0, 1, 0);
    if (waterflag == 1)
    {
        Bird();
    }
    else
        Bird();
    glPopMatrix();
    
    glFlush();
}

void Display6()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    grass();
    pot();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-1.0, -0.9, "So it picked the pebbles one by one & put it in the pot...");
    glLoadIdentity();
    glTranslatef(1.5, 0.0, 0.0);
    tree();
    glLoadIdentity();
    glTranslatef(-0.17, 0.0, 0.0);
    sun();
    glLoadIdentity();
    stone();

    glPushMatrix();
    glTranslatef(xpos, yup, 0.0f);
    glRotatef(180, 0, 1, 0);
    Bird();
    glPopMatrix();
    
    if (!pebbleflag)
    {
        glPushMatrix();
        glTranslatef(-0.2, ydown, 0.0f);
        Pebble();
        glPopMatrix();
        
        if (ydown < -0.7)  //stone into pot 
        {
            ydown = 0.5;
        }
    }


    glFlush();
    
    if (xpos >= -0.2 && yup >= -0.25 && dsix == 0)
    {
        waterflag = 1;
        stonereturnflag = 0;
        dsix = 1;
        pebbleflag = 0;
        ydown = 0.2;
    }

}

void Display7()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    grass();
    pot();
    cloud1();
    cloud2();
    glColor3f(0.0, 0.0, 0.0);
    output1(-0.95, -0.9, "Water rised to the top of the pot,");
    output1(-0.95, -0.98, "it drank water and flew away...");
    glTranslatef(0.1f, 0.0f, 0.0f);
    waterdrop();
    glLoadIdentity();
    glTranslatef(1.5, 0.0, 0.0);
    tree();

    glLoadIdentity();
    glTranslatef(-0.17, 0.0, 0.0);
    sun();
    glLoadIdentity();
    stone();

    glPushMatrix();
    if (!flyaway)
    {
        glTranslatef(-0.2f, ydown, 0.0f);
        glRotatef(180, 0, 1, 0);
        Bird();
    }
    else
    {
        glTranslatef(xpos - 0.2, yup - 0.4, 0.0f);
        glRotatef(180, 0, 1, 0);
        Bird();
    }
    glPopMatrix();
    glFlush();
    if (ydown < -0.6)
    {

        flyaway = 1;
        stonereturnflag = 1;
    }
}

void Display8()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    output1(-0.40, 0.5, "MORAL OF THE STORY ");
    output1(-0.80, -0.0, "WHERE THERE IS A WILL THERE IS  A WAY ");

    glFlush();
}

void Keypress(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        printf("1 displayed\n");
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 680);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("THIRSTY CROW");
        glutKeyboardFunc(Keypress);
        glutDisplayFunc(Display1);
        break;
    case '2':
        printf("\n2 Displayed\n");
        position = -1.0f;
        glutDisplayFunc(Display2);
        break;
    case '3':
        printf("\n3 Displayed\n");
        position = -1.0f;
        glutDisplayFunc(Display3);
        break;
    case '4':
        printf("\n4 Displayed\n");
        position = -0.9f;
        glutDisplayFunc(Display4);
        break;
    case '5':
        printf("\n5 Displayed\n");
        position = -0.9f;
        xpos = -1.0;
        ypos = 0.45;
        glutDisplayFunc(Display5);
        break;
    case '6':
        printf("\n6 Displayed\n");
        position = -0.9f;
        xpos = -1.4;
        ypos = -0.85;
        yup = ypos;
        pebbleflag = 1;
        stonereturnflag = 1;
        glutDisplayFunc(Display6);
        break;
    case '7':
        printf("\n7 Displayed\n");
        position = -1.0f;
        glutDisplayFunc(Display7);
        break;
    case '8':
        printf("\nMoral of the Story");
        glutDestroyWindow(1);
        glutInitWindowSize(1240, 680);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Moral");
        glutKeyboardFunc(Keypress);
        glutDisplayFunc(Display8);
        break;

    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1240, 680);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("THIRSTY CROW");
    glutReshapeFunc(reshape);
    glutDisplayFunc(Display);
    glutKeyboardFunc(Keypress);
    glutTimerFunc(100, move, 0);
    glutMainLoop();
    return 0;
}