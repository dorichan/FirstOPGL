#include "FIRSTOPGL.h"

FirstOPGL::FirstOPGL(float x, float y, float z)
	: Shape( x, y, z, const_cast<GLfloat*>(blue), 
	                  const_cast<GLfloat*>(white)){
	int number = rand()%6;

	_points = number +1; 

	if(  number == 0 ){
		setMaterial(green, white);
	}
	else if (  number == 1 ){
		setMaterial(grey, white);
	}
	else if (  number == 2 ){
		setMaterial(red, white);
	}
	else if (  number == 3 ){
		setMaterial(yellow, white);
	}
	else if (  number == 4 ){
		setMaterial(purple, white);
	}
}