/* tcc -lglfw  -lGLEW -run main.c */

#define GLEW_STATIC
#include <GL/glew.h>
#include <unistd.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
  /* init code */
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL); /* Windowed Mode */
  /* GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), NULL); /* Fullscreen Mode */
  glfwMakeContextCurrent(window);
  glewExperimental = GL_TRUE;
  glewInit();
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  /* printf("%u\n", vertexBuffer); */
  while(!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
      glfwSetWindowShouldClose(window, GL_TRUE);}
  }
  glfwTerminate();
  return 0;
}
