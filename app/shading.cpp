#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Initialize light source
void init_light(int light_source, float lx, float ly, float lz, float lr, float lg, float lb) {
   float light_position[] = { lx, ly, lz, 0.0f};
   float light_color[] = { lr, lg, lb, 1.0f};

   // Initialize lighting for openGL
   glEnable(GL_LIGHTING);

   // Enable the light source
   glEnable(light_source);

   // Setting the position property of the light source
   glLightfv(light_source, GL_POSITION, light_position);

   // Setting the material properties of the light source
   glLightfv(light_source, GL_AMBIENT, light_color);
   glLightfv(light_source, GL_DIFFUSE, light_color);
   glLightfv(light_source, GL_SPECULAR, light_color);

   // Setting the intensity properties of the light source
   glLightf(light_source, GL_CONSTANT_ATTENUATION, 1.0);
   glLightf(light_source, GL_LINEAR_ATTENUATION, 0.0);
   glLightf(light_source, GL_QUADRATIC_ATTENUATION, 0.0);
}


// Make an approximation of the material's color
// based on the RBG it reflects from the lighting
void init_material(float ka, float kd, float ks, float kp, float mr, float mg, float mb)
{
   // Material variables for different colors
   float ambient[] = { ka * mr, ka * mg, ka * mb, 1.0 };
   float diffuse[] = { kd * mr, kd * mg, kd * mb, 1.0 };
   float specular[] = { ks * mr, ks * mg, ks * mb, 1.0 };

   // Initialize material for different lighting 
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
   glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kp);
}
