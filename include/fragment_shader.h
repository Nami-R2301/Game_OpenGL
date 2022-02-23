//
// Created by nami on 2022-02-23.
//

#ifndef GAME_OPENGL_FRAGMENT_H
#define GAME_OPENGL_FRAGMENT_H
#include <GLES3/gl3.h>

//Fragment Shader source code
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "uniform vec4 color;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = color;\n"
                                   "}\n\0";

class fragment
{
  fragment();
  void Delete();

  GLuint fragment_shader;
};

fragment::fragment()
{
  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fragmentShaderSource, nullptr);
  // Compile the shaders into machine code to pass on to the GPU.
  glCompileShader(fragment_shader);
}

void fragment::Delete()
{
  // Delete the shaders since they have been compiled and linked in the program.
  glDeleteShader(fragment_shader);
}


#endif //GAME_OPENGL_FRAGMENT_H
