#include <cmath>
#include "sphere.hpp"

// Code for handling collision between two spheres
// or a sphere and a wall


// Handles collision between two spheres
// Precondition: The two given spheres are not the same sphere
void sphere_collision(sphere s1, sphere s2) {

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
