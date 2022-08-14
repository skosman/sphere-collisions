#ifndef SP_SPHERE_HPP
#define SP_SPHERE_HPP

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

    bool operator==(const sphere &s) const;

  private:
    // Id of the sphere
    int id_;
    // Radius of the sphere
    float radius_;
    // Mass of the sphere
    float mass_;

    // Vector containing the x, y, and z coordinate positions
    std::vector<float> position_;

    // Vector containing the x, y, and z coordinate velocity
    std::vector<float> velocity_;
};

#endif