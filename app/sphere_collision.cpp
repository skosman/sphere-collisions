#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


// Main program that runs the sphere collision program
int main(int argc, char *argv[]) {
  // Initialize GLUT to create an openGL window
  glutInit(&argc, argv);
  // Create a 600 by 600 window
  int WINDOW = 600;
  glutInitWindowSize(WINDOW, WINDOW);
  // Position the window in the top left side of the screen
  glutInitWindowPosition(WINDOW / 4, WINDOW / 4);
  // Set the display mode to RGB color, double buffer for smooth animation, adn depth buffer
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  // Create window with given title
  glutCreateWindow("Sphere Collision");


  return 0;
}