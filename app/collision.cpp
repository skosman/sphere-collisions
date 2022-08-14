#include <cmath>
#include <vector>
#include "sphere.hpp"

// Code for handling collision between two spheres
// or a sphere and a wall


// Handles collision between two spheres
// Precondition: The two given spheres are not the same sphere
void sphere_collision(sphere s1, sphere s2) {
  float vec_x = s1.get_x() - s2.get_x();
  float vec_y = s1.get_y() - s2.get_y();
  float vec_z = s1.get_z() - s2.get_z();

  // Normalize vector
  float dist = std::sqrt((vec_x * vec_x) + (vec_y * vec_y) + (vec_z * vec_z));
  vec_x /= dist;
  vec_y /= dist;
  vec_z /= dist;

  // Calculate the dot product of sphere 2
  float x_1 = vec_x * s1.get_velocity()[0] + vec_y * s1.get_velocity()[1] + vec_z * s1.get_velocity()[2];

  // Multiple the result of the dot product with sphere 1 velocity x
  float vec_1_x_0 = s1.get_velocity()[0] * x_1;
  float vec_1_x_1 = s1.get_velocity()[1] * x_1;
  float vec_1_x_2 = s1.get_velocity()[2] * x_1;

  // Subtract 
  float vec_1_y_0 = s1.get_velocity()[0] - vec_1_x_0;
  float vec_1_y_1 = s1.get_velocity()[1] - vec_1_x_1;
  float vec_1_y_2 = s1.get_velocity()[2] - vec_1_x_2;

  // Repeat the above with the sphere 2
  vec_x *= -1;
  vec_y *= -1;
  vec_z *= -1;

   // Calculate the dot product of sphere 2
  float x_2 = vec_x * s2.get_velocity()[0] + vec_y * s2.get_velocity()[1] + vec_z * s2.get_velocity()[2];

   // Multiple the result of the dot product with sphere 1 velocity x
  float vec_2_x_0 = s2.get_velocity()[0] * x_2;
  float vec_2_x_1 = s2.get_velocity()[1] * x_2;
  float vec_2_x_2 = s2.get_velocity()[2] * x_2;

  // Subtract 
  float vec_2_y_0 = s2.get_velocity()[0] - vec_2_x_0;
  float vec_2_y_1 = s2.get_velocity()[1] - vec_2_x_1;
  float vec_2_y_2 = s2.get_velocity()[2] - vec_2_x_2;

  // Now calculate the final velocity
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

  // Update the velocity of the first sphere
  s2.set_velocity(vel_2_x, vel_2_y, vel_2_z);
}

 // Calculate distance between spheres to check if they are colliding
void sphere_collision_detection(sphere s1, sphere s2) {
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
    sphere_collision(s1, s2);
  }
}

// Handles collision between the wall and a sphere
void wall_collision(sphere s) {

}
