#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <gl\glut.h>

using namespace std;

enum type{ SPHERE, CUBE, CONE };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat grey[] = { 0.5, 0.5, 0.5, 1.0 };
const GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
const GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
const GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
const GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };
const GLfloat purple[] = { 1.0, 0.0, 1.0, 1.0 };

class Shape{
	protected:
		float _translateX, _translateY, _translateZ;
		float _rotateX, _rotateY, _rotateZ;
		float _scaleX, _scaleY, _scaleZ;
		float _radius;
		GLfloat* _ambient;
		GLfloat* _diffuse;
		type _type;
	public:
		Shape(float translateX=0, float translateY=0, float translateZ=0, 
			  float rotateX=0, float rotateY=0, float rotateZ=0, 
			  float scaleX=1, float scaleY=1, float scaleZ=1, 
			  GLfloat* ambient =  const_cast<GLfloat*>(grey), 
			  GLfloat* diffuse =  const_cast<GLfloat*>(white));
		Shape(float translateX, float translateY, float translateZ, 
			  GLfloat* ambient, GLfloat* diffuse);
		void setTranslate(float translateX, float translateY, float translateZ);
		void setTranslateX(float translateX){ _translateX = translateX;};
		void setTranslateY(float translateY){ _translateY = translateY;};
		void setTranslateZ(float translateZ){ _translateZ = translateZ;};
		float getTranslateX(){ return _translateX; };
		float getTranslateY(){ return _translateY; };
		float getTranslateZ(){ return _translateZ; };
		void setRadius(float radius) { _radius = radius; };
		void makeCube(){ _type = CUBE; };
		void setMaterial(const GLfloat ambient[], const GLfloat diffuse[]);
		virtual void move(float x, float y, float z);
		virtual void draw();
};

#endif