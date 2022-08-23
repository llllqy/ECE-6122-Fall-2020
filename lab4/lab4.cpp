/*
Author: Qingyuan Liu
Class: ECE6122
Last Date Modified: 2020/10/29
Description:
This file is used to display the 3D maze and everything in it. Pressing the R key can 
rotate the maze clockwise by 5 degrees each time the key is pressed.
//set the coordinates of the center of the maze is (0,0)

*/
#include <GL/glut.h>
#include "ECE_ghost.h"
#include "ECE_Pacman.h"

GLUquadricObj* quadratic{ nullptr };

ECE_Pacman pacman;
ECE_ghost ghost1;     //create four ghosts
ECE_ghost ghost2;
ECE_ghost ghost3;
ECE_ghost ghost4;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0,1.0 };              //set the light
    GLfloat light_position[] = { 20.0, 20.0, 20.0,0.0 };

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    if (!quadratic)
        quadratic = gluNewQuadric();
}

//draw maze
void maze(void)
{
    //glColor3f(30.0 / 255, 144.0 / 255, 1.0f);
    GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
    GLfloat earth_mat_diffuse[] = { 30.0 / 255, 144.0 / 255, 1.0f };
    GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
    GLfloat earth_mat_emission[] = { 0.01f, 0.0f, 0.0f, 1.0f };
    GLfloat earth_mat_shininess = 60.0f;

    // GL_AMBIENT 材质的环境颜色 
    glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
    // GL_DIFFUSE 材质的散射颜色
    glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
    // GL_SPECULAR 材质的镜面反射颜色
    glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
    // GL_EMISSION 材质的发射光颜色
    glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
    // GL_SHININESS 镜面反射指数
    glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, -10.0f);
    glRotatef(90.0f, 0.0, 1.0f, 0.0);
    gluCylinder(quadratic, 0.1, 0.1, 18.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, 11.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 18.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, 5.0f);
    glRotatef(90.0f, 0.0, 1.0f, 0.0);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -10.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 5.0f);
    glRotatef(90.0f, 0.0, 1.0f, 0.0);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, -8.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, -7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -8.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, -5.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -5.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -8.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, -8.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, -7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, -3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, -3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, -1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, 1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, 1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 3.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(8.0f, 0.0f, 7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, 5.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, 9.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 5.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, 7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, 5.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, 9.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 5.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, -5.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, -1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 1.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 3.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, 7.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(7.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, -8.0f);
    gluCylinder(quadratic, 0.1, 0.1, 1.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 3.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 7.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, 0.0f, -1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, 0.0f, -1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, 1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f, 0.0f, 1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0f, 0.0f, 1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, 1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, -5.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f, 0.0f, -5.0f);
    gluCylinder(quadratic, 0.1, 0.1, 4.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, -10.0f);
    gluCylinder(quadratic, 0.1, 0.1, 7.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.0f, 0.0f, -10.0f);
    gluCylinder(quadratic, 0.1, 0.1, 7.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9.0f, 0.0f, 3.0f);
    gluCylinder(quadratic, 0.1, 0.1, 8.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.0f, 0.0f, 3.0f);
    gluCylinder(quadratic, 0.1, 0.1, 8.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, -3.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, 1.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0f, 0.0f, -3.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0f, 0.0f, 5.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6.0f, 0.0f, 5.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, 7.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.0f, 0.0f, 7.0f);
    gluCylinder(quadratic, 0.1, 0.1, 2.0, 10, 10);
    glPopMatrix();
}

//draw coins
int coin[152][3] = 
{ 
    //line -9
    {-8,-9,0},{-7,-9,0},{-6,-9,0},{-5,-9,0},{-4,-9,0},{-3,-9,0},{-2,-9,0},{-1,-9,0},{1,-9,0},{2,-9,0},{3,-9,0},{4,-9,0},{5,-9,0},{6,-9,0},{7,-9,0},{8,-9,0},
    //line-8
    {-5,-8,0},{-1,-8,0},{1,-8,0},{5,-8,0},
    //line-7
    {-8,-7,0},{-5,-7,0},{-1,-7,0},{1,-7,0},{5,-7,0},{8,-7,0},
    //line-6
    {-8,-6,0},{-7,-6,0},{-6,-6,0},{-5,-6,0},{-4,-6,0},{-3,-6,0},{-2,-6,0},{-1,-6,0},{0,-6,0},{1,-6,0},{2,-6,0},{3,-6,0},{4,-6,0},{5,-6,0},{6,-6,0},{7,-6,0},{8,-6,0},
    //line-5
    {-8,-5,0},{-5,-5,0},{-3,-5,0},{3,-5,0},{5,-5,0},{8,-5,0},
    //line-4
    {-8,-4,0},{-7,-4,0},{-6,-4,0},{-5,-4,0},{-3,-4,0},{-2,-4,0},{-1,-4,0},{1,-4,0},{2,-4,0},{3,-4,0},{5,-4,0},{6,-4,0},{7,-4,0},{8,-4,0},
    //line-3
    {-5,-3,0},{5,-3,0},
    //line-2
    {-5,-2,0},{5,-2,0},
    //line-1
    {-5,-1,0},{5,-1,0},
    //line0
    {-5,0,0},{5,0,0},
    //line1
    {-5,1,0},{5,1,0},
    //line2
    {-5,2,0},{5,2,0},
    //line3
    {-5,3,0},{5,3,0},
    //line4
    {-8,4,0},{-7,4,0},{-6,4,0},{-5,4,0},{-4,4,0},{-3,4,0},{-2,4,0},{-1,4,0},{1,4,0},{2,4,0},{3,4,0},{4,4,0},{5,4,0},{6,4,0},{7,4,0},{8,4,0},
    //line5
    {-8,5,0},{-5,5,0},{-1,5,0},{1,5,0},{5,5,0},{8,5,0},
    //line6
    {-7,6,0},{-5,6,0},{-4,6,0},{-3,6,0},{-2,6,0},{-1,6,0},{1,6,0},{2,6,0},{3,6,0},{4,6,0},{5,6,0},{7,6,0},
    //line7
    {-7,7,0},{-5,7,0},{-3,7,0},{3,7,0},{5,7,0},{7,7,0},
    //line8
    {-8,8,0},{-7,8,0},{-6,8,0},{-5,8,0},{-3,8,0},{-2,8,0},{-1,8,0},{1,8,0},{2,8,0},{3,8,0},{5,8,0},{6,8,0},{7,8,0},{8,8,0},
    //line9
    {-8,9,0},{-1,9,0},{1,9,0},{8,9,0},
    //line10
    {-8,10,0},{-7,10,0},{-6,10,0},{-5,10,0},{-4,10,0},{-3,10,0},{-2,10,0},{-1,10,0},{0,10,0},{1,10,0},{2,10,0},{3,10,0},{4,10,0},{5,10,0},{6,10,0},{7,10,0},{8,10,0},
};

void coins(void)
{
    // glColor3f(240.0 / 255, 1.0f, 1.0f);
    GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
    GLfloat earth_mat_diffuse[] = { 240.0 / 255, 1.0f, 1.0f }; 
    GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat earth_mat_shininess = 60.0f;

    // GL_AMBIENT 材质的环境颜色 
    glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
    // GL_DIFFUSE 材质的散射颜色
    glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
    // GL_SPECULAR 材质的镜面反射颜色
    glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
    // GL_EMISSION 材质的发射光颜色
    glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
    // GL_SHININESS 镜面反射指数
    glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);//draw coins
    for (int i = 0; i < 152; i++)
    {
        if (coin[i][2] == 0)
        {
            glPushMatrix();
            glTranslatef(coin[i][0], 0.0f, coin[i][1]);
            glutSolidSphere(0.12, 100, 100);//coins radius and basic conditions
            glPopMatrix();
        }
    }

}

//draw powerups
void powerUps(void)
{
    //glColor3f(245.0 / 255, 222.0 / 255, 179.0 / 255);
    GLfloat earth_mat_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat earth_mat_diffuse[] = { 0.68, 0.58, 0.44 };
    GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat earth_mat_emission[] = { 0.68, 0.58, 0.44, 1.0f };
    GLfloat earth_mat_shininess = 60.0f;

    // GL_AMBIENT 材质的环境颜色 
    glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
    // GL_DIFFUSE 材质的散射颜色
    glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
    // GL_SPECULAR 材质的镜面反射颜色
    glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
    // GL_EMISSION 材质的发射光颜色
    glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
    // GL_SHININESS 镜面反射指数
    glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
    glPushMatrix();
    glTranslatef(-8.0f, 0.0f, -8.0f);
    glRotatef(90.0f, 1.0, 0.0f, 0.0);
    gluDisk(quadratic, 0.0, 0.35, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(245.0 / 255, 222.0 / 255, 179.0 / 255);
    glTranslatef(8.0f, 0.0f, -8.0f);
    glRotatef(90.0f, 1.0, 0.0f, 0.0);
    gluDisk(quadratic, 0.0, 0.35, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(245.0 / 255, 222.0 / 255, 179.0 / 255);
    glTranslatef(-8.0f, 0.0f, 6.0f);
    glRotatef(90.0f, 1.0, 0.0f, 0.0);
    gluDisk(quadratic, 0.0, 0.35, 40, 40);
    glPopMatrix();

    glPushMatrix();
    glColor3f(245.0 / 255, 222.0 / 255, 179.0 / 255);
    glTranslatef(8.0f, 0.0f, 6.0f);
    glRotatef(90.0f, 1.0, 0.0f, 0.0);
    gluDisk(quadratic, 0.0, 0.35, 40, 40);
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING);

    glRotatef(5.0, 0.0, 1.0, 0.0);//set rotate point controlled by keyboard

    maze();
    coins();
    powerUps();
    pacman.draw();
    ghost1.drawpink();
    ghost2.drawred();
    ghost3.drawgreen();
    ghost4.draworange();

    glDisable(GL_LIGHTING);
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);   //the look angle 
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) 
    {
    case 'R':
        glutPostRedisplay();
        break;
    case 'r':
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Maze");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);   //keyboard response
    glutMainLoop();
    return 0;
}