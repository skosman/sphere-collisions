#include "sphere.hpp"

#include <vector>

  // Sphere constructor
  sphere::sphere(int id, float radius, float mass, std::vector<float> position, std::vector<float> velocity) {
    id_ = id;
    radius_ = radius;
    mass_ = mass;
    position_ = position;
    velocity_ = velocity;
  }

  // Returns the id of the sphere
  int sphere::get_id() const {
    return id_;
  }

  // Returns the radius of the sphere
  float sphere::get_radius() const {
    return radius_;
  }
  // Returns the mass of the sphere
  float sphere::get_mass() const {
    return mass_;
  }

  // Get the x, y, and z position coordinates of the sphere
  std::vector<float> sphere::get_position() const {
    return position_;
  }

  // Get x position coordinate of the sphere
  float sphere::get_x() const {
    return position_[0];
  }

  // Get y position coordinate of the sphere
  float sphere::get_y() const {
    return position_[1];
  }

  // Get z position coordinate of the sphere
  float sphere::get_z() const {
    return position_[2];
  }

  // Set the x, y, and z position coordinates of the sphere
  void sphere::set_position(float x, float y, float z) {
    // position_
  }

  // Returns the x, y, and z velocity coordinates of the sphere
  std::vector<float> sphere::get_velocity() const {
    return velocity_;
  }

  // Set the x, y, and z velocity coordinates of the sphere
  void sphere::set_velocity(float x, float y, float z) {
    // return velocity_;
  }

    // Check if two spheres are equal based on their id
  bool sphere::operator==(const sphere& s) const {
    return id_ == s.get_id();
  }