#pragma once
/*Pac-man can be drawn as a yellow sphere
* Pac-man is static and does not move.
*/
#include<stdlib.h>
#include<GL\glut.h>

class ECE_Pacman
{
public:
	ECE_Pacman(){}
	
	void draw()
	{
		glPushMatrix();
        GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
        GLfloat earth_mat_diffuse[] = { 1.0f, 1.0f, 0.0f }; // 深红色的球
        GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // 镜面反射出红光
        GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // 自己发出微微的红光
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
		//glColor3f(1.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, 6.0f);
		glutSolidSphere(0.6, 40, 50);
		glPopMatrix();
	}
};