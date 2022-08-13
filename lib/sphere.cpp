#include <sphere.hpp>

#include <vector>

  // Sphere constructor
  sphere::sphere(float radius, float mass, std::vector<float> position, std::vector<float> velocity) {
    radius_ = radius;
    mass_ = mass_;
    position_ = position;
    velocity_ = velocity;
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

  // Returns the x, y, and z velocity coordinates of the sphere
  std::vector<float> sphere::get_velocity() const {
    return velocity_;
  }