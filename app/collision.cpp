#include <cmath>
#include "sphere.hpp"

// Code for handling collision between two spheres
// or a sphere and a wall


// Handles collision between two spheres
// Precondition: The two given spheres are not the same sphere
void sphere_collision(sphere s1, sphere s2) {
  // return if it the same sphere
  if (s1 == s2) {
    return;
  }
}

// Handles collision between the wall and a sphere
void wall_collision(sphere s) {

}
