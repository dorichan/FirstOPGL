#include "Scene.h"

vector<FirstOPGL*> Scene::shapes;
Shape* Scene::player;
int Scene::steps;

void Scene::Initialize()
{
  srand(time(0));
  steps = 0;
  player = new Shape(0, -8, 0, 
		const_cast<GLfloat*>(red), const_cast<GLfloat*>(white));

}

void Scene::Display()
{
  // set up the camera
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 20.0,
            0.0, 0.0, 0.0,
            0.0, 1.0, 0.0);

  // clear the screen
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  player->draw();
  for( int i=0; i < shapes.size(); i++ ){
	  shapes[i]->draw();
  }

  // draw everything and swap the display buffer
  glutSwapBuffers();
} // end Display()

void Scene::Reshape(int width, int height)
{
  if (height == 0)
    return;

  glViewport(0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, width/height, 1.0, 100.0);

  glMatrixMode(GL_MODELVIEW);
} 

void Scene::Animate()
{
	vector<FirstOPGL*>::iterator iter;

	// Colliding with player
	for( iter = shapes.begin(); iter != shapes.end(); iter++){
		if( checkCollision(player->getTranslateX(), player->getTranslateY(),
					   player->getTranslateZ(), 
					   (*iter)->getTranslateX(), (*iter)->getTranslateY(),
					   (*iter)->getTranslateZ(), 1, 1) ){
			shapes.erase(iter);
			break;
		}
	}
	// Reaching the bottom of the screen
	for( iter = shapes.begin(); iter != shapes.end(); iter++){
		if ( (*iter)->getTranslateY() < -10 ){
			shapes.erase(iter);
			break;
		}
	}
	// Animating the spheres
	for( int i=0; i < shapes.size(); i++){

		shapes[i]->move(0, -0.05, 0);
	}
	steps++;

	// Creating new spheres
	if( steps >=50 ){
		for( int i=-10; i < 10; i+=2 ){
				shapes.push_back(new FirstOPGL(i, 8, 0));
		}
		steps = 0;
	}

   glutPostRedisplay();
}


void Scene::specialKeyboardHandler(int key, int x, int y)
{
	switch (key)
	{ 
		case GLUT_KEY_RIGHT: 
		{
			// move sphere
			player->move(2,0,0);
			break;
		} 
		case GLUT_KEY_LEFT: 
		{
			// move sphere
			player->move(-2,0,0);
			break;
		} 
		break;
	}

	glutPostRedisplay();
}

void Scene::Keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
		{
			exit(0);
			break;
		}
		break;
	}
}

bool Scene::checkCollision(float sphereX, float sphereY, float sphereZ,
	                       float sphere2X, float sphere2Y, float sphere2Z,
						   float sphereR, float sphere2R){
	int distance = sqrt( pow( (sphere2X - sphereX), 2) + 
		           pow( (sphere2Y - sphereY), 2) +
		           pow( (sphere2Z - sphereZ), 2));

	if( distance < (sphere2R + sphereR) ){
		cout << "Collide!"  << endl;
		return true;
	}
	else{
		return false;
	}
}