#ifndef SPHERE_HPP
#define SPHERE_HPP


#include <vector>

class sphere {
  public:
    // Sphere constructor
    sphere(int id, float radius, float mass, std::vector<float> position, std::vector<float> velocity);

    // Returns the id of the sphere
    int get_id() const;
    
    // Returns the radius of the sphere
    float get_radius() const;

    // Returns the mass of the sphere
    float get_mass() const;

    // Get the x, y, and z position coordinates of the sphere
    std::vector<float> get_position() const;

    // Get the x position coordinate of the sphere
    float get_x() const;

    // Get the y position coordinate of the sphere
    float get_y() const;

    // Get the z position coordinate of the sphere
    float get_z() const;

    // Set the x, y, and z position coordinates of the sphere
    void set_position(float x, float y, float z);

    // Returns the x, y, and z velocity coordinates of the sphere
    std::vector<float> get_velocity() const;

    // Set the x, y, and z velocity coordinates of the sphere
    void set_velocity(float x, float y, float z);

    // Draw the sphere using openGL
    void draw() const;

    // Binary equals operator
    bool operator==(const sphere &s) const;

  private:
    // Id of the sphere
    int id_;
    // Radius of the sphere
    float radius_;
    // Mass of the sphere
    float mass_;

    // Number of slices of the sphere used to draw the surface
    static const int slices_ = 10;

    // Vectors used to hold the points to create the surface of the sphere
    float x_surface_[slices_ + 1][slices_ + 1];
    float y_surface_[slices_ + 1][slices_ + 1];
    float z_surface_[slices_ + 1][slices_ + 1];

    // Vector containing the x, y, and z coordinate positions
    std::vector<float> position_;

    // Vector containing the x, y, and z coordinate velocity
    std::vector<float> velocity_;

    // Initializes the surface of the sphere to be used for rendering
    void init_surface();
};

#endif