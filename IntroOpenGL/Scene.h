#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include <time.h>
#include "Shape.h"
#include "FirstOPGL.h"
#include <time.h>
#include <gl\glut.h>

using namespace std;

class Scene
{
	private:
		static vector<FirstOPGL*> shapes;
		static Shape* player;
		Scene(){};
		static int steps;
	public:
		static void Display();
		static void Initialize();
		static void Reshape(int width, int height);
		static void Animate();
		static void specialKeyboardHandler(int key, int x, int y);
		static void Keyboard(unsigned char key, int x, int y);
		static bool checkCollision(float sphereX, float sphereY, float sphereZ,
	                       float sphere2X, float sphere2Y, float sphere2Z,
						   float sphereR, float sphere2R);
};

#endif