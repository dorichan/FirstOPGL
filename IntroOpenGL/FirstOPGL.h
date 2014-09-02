#ifndef FIRSTOPGL_H
#define FIRSTOPGL_H

#include <iostream>
#include "Shape.h"
#include <gl\glut.h>

using namespace std;

class FirstOPGL: public Shape{
	private:
		int _points;
	public:
		FirstOPGL(float x, float y, float z) ;
};

#endif