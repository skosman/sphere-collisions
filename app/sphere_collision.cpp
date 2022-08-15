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
// #include "collision.hpp"


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

// Handles collision between two spheres
// Precondition: The two given spheres are not the same sphere
void sphere_collision(int i, int j) {
  sphere &s1 = spheres.at(i);
  sphere &s2 = spheres.at(j);

  float vec_x = s1.get_x() - s2.get_x();
  float vec_y = s1.get_y() - s2.get_y();
  float vec_z = s1.get_z() - s2.get_z();

  // Normalize vector
  float dist = std::sqrt((vec_x * vec_x) + (vec_y * vec_y) + (vec_z * vec_z));
  vec_x /= dist;
  vec_y /= dist;
  vec_z /= dist;

  // Calculate the dot product of sphere 2
  float x_1 = vec_x * s1.get_vx() + vec_y * s1.get_vy() + vec_z * s1.get_vz();

  // Multiple the result of the dot product with sphere 1 velocity x
  float vec_1_x_0 = s1.get_vx() * x_1;
  float vec_1_x_1 = s1.get_vy() * x_1;
  float vec_1_x_2 = s1.get_vz() * x_1;

  // Subtract 
  float vec_1_y_0 = s1.get_vx() - vec_1_x_0;
  float vec_1_y_1 = s1.get_vy() - vec_1_x_1;
  float vec_1_y_2 = s1.get_vz() - vec_1_x_2;

  // Repeat the above with the sphere 2
  vec_x *= -1;
  vec_y *= -1;
  vec_z *= -1;

   // Calculate the dot product of sphere 2
  float x_2 = vec_x * s2.get_vx() + vec_y * s2.get_vy() + vec_z * s2.get_vz();

   // Multiple the result of the dot product with sphere 2 velocity x
  float vec_2_x_0 = s2.get_vx() * x_2;
  float vec_2_x_1 = s2.get_vy() * x_2;
  float vec_2_x_2 = s2.get_vz() * x_2;

  // Subtract 
  float vec_2_y_0 = s2.get_vx() - vec_2_x_0;
  float vec_2_y_1 = s2.get_vy() - vec_2_x_1;
  float vec_2_y_2 = s2.get_vz() - vec_2_x_2;

  // Now calculate the final velocity for both spheres
  float mass_1_final = (s1.get_mass() - s2.get_mass()) / (s1.get_mass() + s2.get_mass());
  float mass_2_final = (2 * s2.get_mass()) / (s1.get_mass() + s2.get_mass());

  float vel_1_x = mass_1_final * vec_1_x_0 + mass_2_final * vec_2_x_0 + vec_1_y_0;
  float vel_1_y = mass_1_final * vec_1_x_1 + mass_2_final * vec_2_x_1 + vec_1_y_1;
  float vel_1_z = mass_1_final * vec_1_x_2 + mass_2_final * vec_2_x_2 + vec_1_y_2;

  // Update the velocity of the first sphere
  s1.set_velocity(vel_1_x, vel_1_y, vel_1_z);

  mass_1_final = (2 * s1.get_mass()) / (s1.get_mass() + s2.get_mass());
  mass_2_final = (s2.get_mass() - s1.get_mass()) / (s1.get_mass() + s2.get_mass());

  float vel_2_x = mass_1_final * vec_1_x_0 + mass_2_final * vec_2_x_0 + vec_2_y_0;
  float vel_2_y = mass_1_final * vec_1_x_1 + mass_2_final * vec_2_x_1 + vec_2_y_1;
  float vel_2_z = mass_1_final * vec_1_x_2 + mass_2_final * vec_2_x_2 + vec_2_y_2;

  // Update the velocity of the second sphere
  s2.set_velocity(vel_2_x, vel_2_y, vel_2_z);
  // s2.set_velocity(0.04f, 0.0f, 0.0f);
}

 // Calculate distance between spheres to check if they are colliding
void sphere_collision_detection(int i, int j) {
  sphere &s1 = spheres.at(i);
  sphere &s2 = spheres.at(j);
  // return if it is the same sphere
  if (s1 == s2) {
    return;
  }

  float dist_x = s1.get_x() - s2.get_x();
  float dist_y = s1.get_y() - s2.get_y();
  float dist_z = s1.get_z() - s2.get_z();

  float dist = std::sqrt((dist_x * dist_x) + (dist_y * dist_y) + (dist_z * dist_z));
  float sum_radii = s1.get_radius() + s2.get_radius();
  // in this case, it is colliding, call sphere_collision
  if (dist < sum_radii) {
    std::cout << "hit" << '\n';
    
    // Move spheres away from each other to allow for collision computation
    float move = (sum_radii / dist) / 2;
    s1.set_x(s1.get_x() + dist_x * move / dist);
    s1.set_y(s1.get_y() + dist_y * move / dist);
    s1.set_z(s1.get_z() + dist_z * move / dist);

    s2.set_x(s2.get_x() + dist_x * move / dist);
    s2.set_y(s2.get_y() + dist_y * move / dist);
    s2.set_z(s2.get_z() + dist_z * move / dist);
    sphere_collision(i, j);
  }
}

// Handles collision between the wall and a sphere
void wall_collision(int i) {
  sphere &s = spheres.at(i);
  float wall = 2.0f;
  float wall_z = -100.0f;
  float negate = -1.0f;
  float radius = s.get_radius();
  // std::cout << s.get_z() << '\n';
  if (s.get_x() > wall - s.get_radius()) {
    s.set_x(wall - radius);
    s.set_vx(s.get_vx() * negate);
  }
  if (s.get_x() < -wall + s.get_radius()) {
    s.set_x(-wall + radius);
    s.set_vx(s.get_vx() * negate);
  }
  if (s.get_y() > wall - s.get_radius()) {
    s.set_y(wall - radius);
    s.set_vy(s.get_vy() * negate);
  }
  if (s.get_y() < -wall + s.get_radius()) {
    s.set_y(-wall + radius);
    s.set_vy(s.get_vy() * negate);
  }
  if (s.get_z() > wall - s.get_radius()) {
    s.set_z(wall - radius);
    s.set_vz(s.get_vz() * negate);
  }
  if (s.get_z() < -wall + s.get_radius()) {
    s.set_z(-wall + radius);
    s.set_vz(s.get_vz() * negate);
  }

  // Update the ball position
  s.set_x(s.get_x() + s.get_vx());
  s.set_y(s.get_y() + s.get_vy());
  s.set_z(s.get_z() + s.get_vz());
}

// Callback function that will be used to refresh the window
void timer_callback(int value) {
  for (int i = 0; i < spheres.size(); ++i) {

    for (int j = 0; j < spheres.size(); ++j) {
      sphere_collision_detection(i, j);
    }

    wall_collision(i);
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
   std::vector<float> velocity1 = {0.01f, 0.02f, 0.0f};
   float radius1 = 0.2;
   
   sphere s1(0, radius1, position1, velocity1);
   spheres.push_back(s1);

   std::vector<float> position2 = {1.0f, 1.0f, 0.0f};
   std::vector<float> velocity2 = {-0.04f, 0.02f, 0.0f};
   float radius2 = 0.3;

   sphere s2(1, radius2, position2, velocity2);
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