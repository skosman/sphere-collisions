#include <GL/glew.h>
#include <GLFW/glfw3.h> // GLFW Helper library
#include <iostream>


// Initial setup for program using https://antongerdelan.net/opengl/hellotriangle.html
// as a reference 

// Use OpenGL Shader Langiage to define 
// where the 3d points should be displayed
const char* vertex_shader =
  "#version 400\n"
  "in vec3 vp;"
  "void main() {"
  "  gl_Position = vec4(vp, 1.0);"
  "}";

// Use OpenGL Shader Langiage to color the surface
const char* fragment_shader =
  "#version 400\n"
  "out vec4 frag_colour;"
  "void main() {"
  "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
  "}";


int main() {
  // Start GL context and OS window using the GLFW helper library
  if (!glfwInit()) {
    std::cout << "Error: Could not start GLFW\n";
  }

  // Create 640x480  window
  GLFWwindow *window = glfwCreateWindow(640, 480, "Sphere Collision", NULL, NULL);
  if (!window) {
    std::cout << "Error: Could not open window with GLFW\n";
    glfwTerminate();
    return 1;
  }

  // Give window OpenGL context
  glfwMakeContextCurrent(window);

    // start GLEW extension handler
  glewExperimental = GL_TRUE;
  glewInit();

  // get version info
  const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte* version = glGetString(GL_VERSION); // version as a string
  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);


  // tell GL to only draw onto a pixel if the shape is closer to the viewer
  glEnable(GL_DEPTH_TEST); // enable depth-testing
  glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

  // Define triangle from 3 x-y-z coordinates
  float points[] = {
    0.0f,  0.5f,  0.0f,
    0.5f, -0.5f,  0.0f,
    -0.5f, -0.5f,  0.0f
  };

  // Copy points into graphics card in unit called vertex buffer object (vbo)
  GLuint vbo = 0;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);

  // use vertex array object (vao) to remember vertex buffer and it's memory layout
  GLuint vao = 0;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

  // Load the vertex shader and fragment shader defined at the top into GL shader
  GLuint vs = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vs, 1, &vertex_shader, NULL);
  glCompileShader(vs);
  GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fs, 1, &fragment_shader, NULL);
  glCompileShader(fs);

  // Bring the compiled shaders into a GPU shader program
  GLuint shader_programme = glCreateProgram();
  glAttachShader(shader_programme, fs);
  glAttachShader(shader_programme, vs);
  glLinkProgram(shader_programme);



  while(!glfwWindowShouldClose(window)) {
    // wipe the drawing surface clear
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(shader_programme);
    glBindVertexArray(vao);
    // draw points 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_TRIANGLES, 0, 3);
    // update other events like input handling 
    glfwPollEvents();
    // put the stuff we've been drawing onto the display
    glfwSwapBuffers(window);
  }

  // close GL context and any other GLFW resources
  glfwTerminate();
  return 0;

}