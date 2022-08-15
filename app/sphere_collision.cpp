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

  // Draw each ball witin the list of spheres
  for(sphere& s: spheres) {
    s.draw();
  }

  glutSwapBuffers();
}

// Callback function that will be used to refresh the window
void timer_callback(int value) {
  for(sphere& s: spheres) {

    // Handle the sphere bouncing off of walls
    float wall = 2.0f;
    float wall_z = -100.0f;
    float negate = -1.0f;
    float radius = s.get_radius();
    // std::cout << s.get_z() << '\n';
    if (s.get_x() > wall - s.get_radius()) {
      std::cout << "1: hit x" << '\n';
      s.set_x(wall - radius);
      s.set_vx(s.get_vx() * negate);
    }
    if (s.get_x() < -wall + s.get_radius()) {
      std::cout << "2: hit x" << '\n';
      s.set_x(-wall + radius);
      s.set_vx(s.get_vx() * negate);
    }
    if (s.get_y() > wall - s.get_radius()) {
      std::cout << "1: hit y" << '\n';
      s.set_y(wall - radius);
      s.set_vy(s.get_vy() * negate);
    }
    if (s.get_y() < -wall + s.get_radius()) {
      std::cout << "2: hit y" << '\n';
      s.set_y(-wall + radius);
      s.set_vy(s.get_vy() * negate);
    }
    if (s.get_z() > wall - s.get_radius()) {
      std::cout << "1: hit z" << '\n';
      s.set_z(wall - radius);
      s.set_vz(s.get_vz() * negate);
    }
    if (s.get_z() < -wall + s.get_radius()) {
      std::cout << "2: hit z" << '\n';
      s.set_z(-wall + radius);
      s.set_vz(s.get_vz() * negate);
    }

    // Update the ball position
    s.set_x(s.get_x() + s.get_vx());
    s.set_y(s.get_y() + s.get_vy());
    s.set_z(s.get_z() + s.get_vz());
  }

  glutPostRedisplay();
  glutTimerFunc(20, timer_callback, 0);
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
   std::vector<float> position1 = {1.0f, 0.0f, 0.0f};
   std::vector<float> velocity1 = {0.07f, 0.02f, 0.0f};
   float radius1 = 0.2;
   
   sphere s1(1, radius1, position1, velocity1);
   spheres.push_back(s1);

   std::vector<float> position2 = {1.6f, 0.6f, 0.0f};
   std::vector<float> velocity2 = {-0.04f, 0.02f, 0.0f};
   float radius2 = 0.08;

   sphere s2(2, radius2, position2, velocity2);
   spheres.push_back(s2);
}

// Initialize OpenGL graphics
void init_gl() {
  // Set background color to black and opaque
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  // Set background depth to farthest
  glClearDepth(1.0f);
  // Enable depth testing
  glEnable(GL_DEPTH_TEST);
  // Set the depth comparison function to less then or equal
  glDepthFunc(GL_LEQUAL);
  // Enable smooth shading for to help round spheres
  glShadeModel(GL_SMOOTH);
}

// Callback function for handling the window-resize event
// Is called when the window first appears and when the window is resized
void reshape_callback(int width, int height) {

  // Set the viewport to match the new window
  glViewport(0, 0, width, height);

  // Operate on the projection matrix
  glMatrixMode(GL_PROJECTION);
  
  // Reset the projection matrix
  glLoadIdentity();
  float RADIUS = 2;

  glOrtho(-RADIUS, RADIUS, -RADIUS, RADIUS, -RADIUS, RADIUS);

  // Compute the aspect ratio for the window
  // float aspect =(float)width / (float)height;

  // Set the view to perspective projection
  // Tranforms the view into a 2x2x1 cuboid
  // gluPerspective(45.0f, aspect, 0.1f, 100.0f);
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
  // Set the display mode to RGB color, double buffer for smooth animation, and depth buffer
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  // Create window with given title
  glutCreateWindow("Sphere Collision");

  // Add callback functions to display and handle user input
  glutDisplayFunc(display_callback);
  glutReshapeFunc(reshape_callback); 
  glutTimerFunc(10, timer_callback, 0);
  glutSpecialFunc(keyboard_callback);

  // Initialize OpenGL and the spheres to be displayed
  init_gl();
  init_spheres();
  // Will continuously loop to render the program
  glutMainLoop();

  return 0;
}