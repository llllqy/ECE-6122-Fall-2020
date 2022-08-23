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
        GLfloat earth_mat_diffuse[] = { 1.0f, 1.0f, 0.0f }; // ���ɫ����
        GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // ���淴������
        GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // �Լ�����΢΢�ĺ��
        GLfloat earth_mat_shininess = 60.0f;

    // GL_AMBIENT ���ʵĻ�����ɫ 
        glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
    // GL_DIFFUSE ���ʵ�ɢ����ɫ
        glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
    // GL_SPECULAR ���ʵľ��淴����ɫ
        glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
    // GL_EMISSION ���ʵķ������ɫ
        glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
    // GL_SHININESS ���淴��ָ��
        glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);
		//glColor3f(1.0f, 1.0f, 0.0f);
		glTranslatef(0.0f, 0.0f, 6.0f);
		glutSolidSphere(0.6, 40, 50);
		glPopMatrix();
	}
};