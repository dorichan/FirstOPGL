
//#include <cstdlib>
#include <vector>
#include "Scene.h"
#include <gl\glut.h>


const GLfloat LightColor[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat LightPos[] = { 0.0, 0.0, 10.0, 1.0 };

int main(int argc, char **argv)
{
 
  Scene::Initialize();
  // Setup the basic GLUT stuff
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // Create the window
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Intro to OpenGL with GLUT");

  // setup scene for lights  
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);	
  glLightfv(GL_LIGHT0, GL_AMBIENT, LightColor);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LightColor);
  glLightfv(GL_LIGHT0, GL_SPECULAR, LightColor);

  // Register the event callback functions
  glutDisplayFunc(Scene::Display); 
  glutReshapeFunc(Scene::Reshape);
  glutIdleFunc(Scene::Animate);
  glutKeyboardFunc(Scene::Keyboard);
  glutSpecialFunc(Scene::specialKeyboardHandler);

  glutMainLoop();   
   
  return 0;
} 



			 
