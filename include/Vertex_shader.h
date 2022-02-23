//
// Created by nami on 2022-02-23.
//

#ifndef GAME_OPENGL_VERTEX_H
#define GAME_OPENGL_VERTEX_H
#include <GLES3/gl3.h>

// Vertex Shader source code
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "uniform float size;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(size * aPos.x, size * aPos.y, size * aPos.z, 1.0);\n"
                                 "}\0";

class Vertex
{
public:
  Vertex();
  void Delete();

private:
  GLuint vertex_shader;
};


Vertex::Vertex()
{
  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  //Set the source code in shader to the source code in the array of strings specified by string.
  glShaderSource(vertex_shader, 1, &vertexShaderSource, nullptr);
  // Compile the shaders into machine code to pass on to the GPU.
  glCompileShader(vertex_shader);
}

void Vertex::Delete()
{
  // Delete the shader when it's compiled and linked to a program.
  glDeleteShader(vertex_shader);
}

#endif //GAME_OPENGL_VERTEX_H
