#include <GL/glew.h>
#include <GLFW/glfw3.h> // GLFW Helper library
#include <iostream>


// Initial setup for program using https://antongerdelan.net/opengl/hellotriangle.html
// as a reference 

// TODO: Add initial sphere objects to render

// Callback function for keyboard input
// TODO: Update function to handle the up and down arrow
// for adding and removing spheres
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << "Keyboard input" << key;
}

int main() {
  // Start GL context and OS window using the GLFW helper library
  if (!glfwInit()) {
    std::cout << "Error: Could not start GLFW\n";
    return 1;
  }

  // For macOs
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create 640x480 gflw window
  GLFWwindow *window = glfwCreateWindow(640, 480, "Sphere Collision", NULL, NULL);
  if (!window) {
    std::cout << "Error: Could not open window with GLFW\n";
    glfwTerminate();
    return 1;
  }


  // Give window OpenGL context
  glfwMakeContextCurrent(window);
  // Tell GL to capture keyboard input
  glfwSetKeyCallback(window, key_callback);

  // start GLEW extension handler
  glewExperimental = GL_TRUE;
  glewInit();

  // Tell GL to only draw onto a pixel if the shape is closer to the viewer
  glEnable(GL_DEPTH_TEST); // enable depth-testing
  glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

  // Loop that renders items
  while(!glfwWindowShouldClose(window)) {
    // wipe the drawing surface clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // update other events like input handling 
    glfwPollEvents();
    // put the stuff we've been drawing onto the display
    glfwSwapBuffers(window);
  }

  // close GL context and any other GLFW resources
  glfwTerminate();
  return 0;

}