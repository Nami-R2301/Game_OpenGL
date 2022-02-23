//
// Created by nami on 2022-02-23.
//

#ifndef GAME_OPENGL_VAO_H
#define GAME_OPENGL_VAO_H
#include <GLES3/gl3.h>

class vao
{
  vao();
  void Delete();

  GLuint vertex_array_obj;
};

vao::vao()
{
  // Create vertex objects to contain and wrap our data to transfer data following opengl conventions.
  glGenVertexArrays(1, &vertex_array_obj);
  // Make the VAO the current Vertex Array Object by binding it
  glBindVertexArray(vertex_array_obj);
  glBindVertexArray(0);
}

void vao::Delete()
{
  glDeleteVertexArrays(1, &vertex_array_obj);
}


#endif //GAME_OPENGL_VAO_H
