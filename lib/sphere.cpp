#include "sphere.hpp"
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
#include <numbers>
#include <cmath>

  // Sphere constructor
  sphere::sphere(int id, float radius, std::vector<float> position, std::vector<float> velocity) {
    id_ = id;
    radius_ = radius;
    // Calculate the mass of the sphere using the volume where density is equal to 1
    float mass = (4.0 / 3.0) * std::numbers::pi_v<float> * std::pow(radius, 3);
    mass_ = mass;
    position_ = position;
    velocity_ = velocity;
    init_surface();
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

  // Set x position coordinate of the sphere
  void sphere::set_x(float x) {
    position_[0] = x;
  }

  // Set y position coordinate of the sphere
  void sphere::set_y(float y) {
    position_[1] = y;
  }

  // Set z position coordinate of the sphere
  void sphere::set_z(float z) {
    position_[2] = z;
  }

  // Set the x, y, and z position coordinates of the sphere
  void sphere::set_position(float x, float y, float z) {
    std::vector<float> updated_position = {x, y, z};
    position_ = updated_position;
  }

  // Returns the x, y, and z velocity coordinates of the sphere
  std::vector<float> sphere::get_velocity() const {
    return velocity_;
  }

  // Get x velocity coordinate of the sphere
  float sphere::get_vx() const {
    return velocity_[0];
  }

  // Get y velocity coordinate of the sphere
  float sphere::get_vy() const {
    return velocity_[1];
  }

  // Get z velocity coordinate of the sphere
  float sphere::get_vz() const {
    return velocity_[2];
  }

  // Set x velocity coordinate of the sphere
  void sphere::set_vx(float x) {
    velocity_[0] = x;
  }

  // Set y velocity coordinate of the sphere
  void sphere::set_vy(float y) {
    velocity_[1] = y;
  }

  // Set z velocity coordinate of the sphere
  void sphere::set_vz(float z) {
    velocity_[2] = z;
  }

  // Set the x, y, and z velocity coordinates of the sphere
  void sphere::set_velocity(float x, float y, float z) {
    std::vector<float> updated_velocity = {x, y, z};
    velocity_ = updated_velocity;
  }

  // Draw the surface of the sphere using openGL polygon
  void sphere::draw() const {
    for (int i = 0; i < slices_; ++i) {
      for (int j = 0; j < slices_; ++j) {
        // Start drawing a polygon shape
        glBegin(GL_POLYGON);
        
        glNormal3f(x_surface_[i][j], y_surface_[i][j], z_surface_[i][j]);
        glVertex3f(get_x() + radius_ * x_surface_[i][j], get_y() + radius_ * y_surface_[i][j], get_z() + radius_ * z_surface_[i][j]);

        glNormal3f(x_surface_[i][j+1], y_surface_[i][j+1], z_surface_[i][j+1]);
        glVertex3f(get_x() + radius_ * x_surface_[i][j+1], get_y() + radius_ * y_surface_[i][j+1], get_z() + radius_ * z_surface_[i][j+1]);

        glNormal3f(x_surface_[i+1][j+1], y_surface_[i+1][j+1], z_surface_[i+1][j+1]);
        glVertex3f(get_x() + radius_ * x_surface_[i+1][j+1], get_y() + radius_ * y_surface_[i+1][j+1], get_z() + radius_ * z_surface_[i+1][j+1]);

        glNormal3f(x_surface_[i+1][j], y_surface_[i+1][j], z_surface_[i+1][j]);
        glVertex3f(get_x() + radius_ * x_surface_[i+1][j], get_y() + radius_ * y_surface_[i+1][j], get_z() + radius_ * z_surface_[i+1][j]);
        
        // Stop drawing the polygon
        glEnd();
      }
    }
  }

    // Check if two spheres are equal based on their id
  bool sphere::operator==(const sphere& s) const {
    return id_ == s.get_id();
  }

  // Initializesthe surface of the sphere to be used for rendering
  void sphere::init_surface() {
    for (int i = 0; i <= slices_; ++i) {
      float sector_angle = 2.0 * i * std::numbers::pi_v<float> / slices_;
      for (int j = 0; j <= slices_; ++j) {
        float stack_angle = j * std::numbers::pi_v<float> / slices_;
        x_surface_[i][j] = cos(sector_angle) * sin(stack_angle);
        y_surface_[i][j] = sin(sector_angle) * sin(stack_angle);
        z_surface_[i][j] = cos(stack_angle);
      }
    }
  }