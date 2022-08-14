#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <vector>
#include <numbers> 
#include <cmath>
#include <sphere.hpp>

// Vector for holding all the spheres
std::vector<sphere> spheres;

// Callback function that handles displaying the objects in the program
void display_callback() {
  // Clear the color and depth buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Use the model-view matrix
  glMatrixMode(GL_MODELVIEW);
  // Reset the model-view matrix
  glLoadIdentity();

}

// Callback function that will be used to refresh the 
void timer_callback(int value) {

}

// Callback function that handles arrow keys input
void keyboard_callback(int key, int x, int y) {
  if (key == GLUT_KEY_UP) {
    std::cout << "up" << '\n';
  }

  if (key == GLUT_KEY_DOWN) {
    std::cout << "down" << '\n';
  }
  
}

// Intialize the spheres to be displayed in the program
// TODO: Update to use a file to create spheres
void init_spheres() {
    // Initialize balls with random positions and colors
   std::vector<float> position = {50, 50, 50};
   std::vector<float> velocity = {1.2, -2, 1.7};
   float radius = 7.0;
   // Calculate the mass of the sphere using the volume where density is equal to 1
   float mass = (4.0 / 3.0) * std::numbers::pi_v<float> * std::pow(radius, 3);

   sphere s1(1, radius, mass, position, velocity);
   spheres.push_back(s1);
}

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

  // Add callback functions to display and handle user input
  glutDisplayFunc(display_callback);
  glutTimerFunc(10, timer_callback, 0);
  glutSpecialFunc(keyboard_callback);
  // Will continuously loop to render the program
  glutMainLoop();

  return 0;
}