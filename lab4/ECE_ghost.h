#pragma once
/*
1. Ghost can be made with a sphere for a head and cylinder for body.
2. Each ghost needs to have a unique color a. Red, green, orange, pink
3. The ghosts are static and do not move.
*/
#include<stdlib.h>
#include<GL\glut.h>

class ECE_ghost
{
	GLUquadricObj* quadratic = gluNewQuadric();
public:
	ECE_ghost(){}
	
	void drawpink() //pink ghost
	{
		//glColor3f(255.0 / 255, 192.0 / 255, 203.0 / 255);// pink
		GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 255.0 / 255, 192.0 / 255, 203.0 / 255 }; // 深红色的球
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
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.4);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(quadratic, 0.4f, 0.4f, 0.4f, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.3, 0.4);
		glutSolidSphere(0.4, 20, 20);
		glPopMatrix();
	}

	void drawred()    //red ghost
	{
		//glColor3f(255.0 / 255, 69.0 / 255, 0);// red
		GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 255.0 / 255, 69.0 / 255, 0 }; // 深红色的球
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
		glPushMatrix();
		glTranslatef(0.0, 0.0, -0.4);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(quadratic, 0.4f, 0.4f, 0.4f, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0, 0.3, -0.4);
		glutSolidSphere(0.4, 20, 20);
		glPopMatrix();
	}
	void drawgreen()   //draw green ghost
	{
		//glColor3f();// green
		GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 72.0 / 255, 209.0 / 255, 204.0 / 255}; 
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
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glPushMatrix();
		glTranslatef(-1.0, 0.0, 0.4);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(quadratic, 0.4f, 0.4f, 0.4f, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.0, 0.3, 0.4);
		glutSolidSphere(0.4, 20, 20);
		glPopMatrix();
	}
	void draworange()     //draw orange ghost
	{
		//glColor3f(255.0 / 255, 140.0 / 255, 0);// orange
		GLfloat earth_mat_ambient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 255.0 / 255, 140.0 / 255, 0 }; 
		GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
		GLfloat earth_mat_shininess = 60.0f;

		
		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
	
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		glPushMatrix();
		glTranslatef(1.0, 0.0, 0.4);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(quadratic, 0.4f, 0.4f, 0.4f, 32, 32);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(1.0, 0.3, 0.4);
		glutSolidSphere(0.4, 20, 20);
		glPopMatrix();
	}
};