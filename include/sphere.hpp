#ifndef SP_SPHERE_HPP
#define SP_SPHERE_HPP

#include <vector>

class sphere {
  public:
    // Sphere constructor
    sphere(float radius, float mass, std::vector<float> position, std::vector<float> velocity);

    // Sphere destructor
    ~sphere();

    // Returns the radius of the sphere
    float get_radius() const;
    // Returns the mass of the sphere
    float get_mass() const;

    // Get the x, y, and z position coordinates of the sphere
    std::vector<float> get_position() const;

    // Returns the x, y, and z velocity coordinates of the sphere
    std::vector<float> get_velocity() const;


  private:
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