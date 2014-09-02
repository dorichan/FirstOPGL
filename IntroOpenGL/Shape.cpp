#include "Shape.h"

Shape::Shape(float translateX, float translateY, float translateZ, 
			  float rotateX, float rotateY, float rotateZ, 
			  float scaleX, float scaleY, float scaleZ, 
			  GLfloat* ambient, GLfloat* diffuse)
{
	_translateX = translateX;
	_translateY =  translateY;
	_translateZ = translateZ;
	_rotateX = rotateX;
	_rotateY = rotateY;
	_rotateZ = rotateZ;
	_scaleX = scaleX;
	_scaleY =  scaleY;
	_scaleZ = scaleZ;
	_ambient = const_cast<GLfloat*>(ambient);
	_diffuse = const_cast<GLfloat*>(diffuse);
	_type = SPHERE;
	_radius = 1;
}

Shape::Shape(float translateX, float translateY, float translateZ, 
			  GLfloat* ambient, GLfloat* diffuse)
{
	_translateX = translateX;
	_translateY =  translateY;
	_translateZ = translateZ;
	_rotateX = 0;
	_rotateY = 0;
	_rotateZ = 0;
	_scaleX = 1;
	_scaleY =  1;
	_scaleZ = 1;
	_ambient = const_cast<GLfloat*>(ambient);
	_diffuse = const_cast<GLfloat*>(diffuse);
	_type = SPHERE;
	_radius = 1;
}
void Shape::draw(){
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, _ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, _diffuse);

  glPushMatrix();
  glTranslatef(_translateX, _translateY, _translateZ);
  glRotatef(_rotateX, 1, 0, 0);
  glRotatef(_rotateY, 0, 1, 0);
  glRotatef(_rotateZ, 0, 0, 1);
  glScalef(_scaleX, _scaleY, _scaleZ);
  if( _type == SPHERE ){
	glutSolidSphere(_radius, 20, 20);
  }
  else if( _type == CUBE ){
	glutSolidCube(_radius*2 );
  }

  glPopMatrix();
}

void Shape::setMaterial(const GLfloat ambient[], const GLfloat diffuse[]){

	_ambient = const_cast<GLfloat*>(ambient);
	_diffuse = const_cast<GLfloat*>(diffuse);

}

void Shape::move(float x, float y, float z){

	_translateX += x;
	_translateY += y;
	_translateZ += z;
}