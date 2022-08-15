#ifndef SPHERE_HPP
#define SPHERE_HPP


#include <vector>

class sphere {
  public:
    // Sphere constructor
    sphere(int id, float radius, std::vector<float> position, std::vector<float> velocity);

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

    // Set the x position coordinate of the sphere
    void set_x(float x);

    // Set the y position coordinate of the sphere
    void set_y(float y);

    // Set the z position coordinate of the sphere
    void set_z(float z);

    // Set the x, y, and z position coordinates of the sphere
    void set_position(float x, float y, float z);

    // Returns the x, y, and z velocity coordinates of the sphere
    std::vector<float> get_velocity() const;

    // Get the x velocity coordinate of the sphere
    float get_vx() const;

    // Get the y velocity coordinate of the sphere
    float get_vy() const;

    // Get the z velocity coordinate of the sphere
    float get_vz() const;

    // Set the x velocity coordinate of the sphere
    void set_vx(float x);

    // Set the y velocity coordinate of the sphere
    void set_vy(float y);

    // Set the z velocity coordinate of the sphere
    void set_vz(float z);

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
    // Static and constant as it is the same across all spheres and should not change
    static const int slices_ = 20;

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