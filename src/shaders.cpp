//
// Created by nami on 2022-02-20.
//
#include <GLES3/gl3.h>

class Shader
{
  Shader(const char*, const char*);
  void Activate() const;
  void Delete() const;


  GLuint shader_program = 0;
};

Shader::Shader(const char *vertex_source, const char *fragment_source)
{
  // Create Shaders for our vertex buffer object (VBO).
  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

  //Set the source code in shader to the source code in the array of strings specified by string.
  glShaderSource(vertex_shader, 1, &vertex_source, nullptr);
  glShaderSource(fragment_shader, 1, &fragment_source, nullptr);
  // Compile the shaders into machine code to pass on to the GPU.
  glCompileShader(fragment_shader);
  glCompileShader(vertex_shader);

  // Set our shader program to attach our created shader to it (link source codes like '#include').
  shader_program = glCreateProgram(); // Creates an empty object program (.o).
  glAttachShader(shader_program, vertex_shader);
  glAttachShader(shader_program, fragment_shader);

  // Links all source codes (shaders) in the program given as argument, creating the executable.
  glLinkProgram(shader_program);

  // Delete the shaders since they have been compiled and linked in the program.
  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
}

void Shader::Activate() const
{
  glUseProgram(shader_program);
}

void Shader::Delete() const
{
  glDeleteProgram(shader_program);
}