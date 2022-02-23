//
// Created by nami on 2022-02-23.
//

#ifndef GAME_OPENGL_VBO_H
#define GAME_OPENGL_VBO_H
#include <GLES3/gl3.h>

class vbo
{
  vbo();
  void Delete();

  GLuint vertex_buffer_obj;
};


vbo::vbo()
{
  // Create vertex objects to contain and wrap our data to transfer data following opengl conventions.
  glGenBuffers(1, &vertex_buffer_obj); // Create empty buffer for our vertex data.
  glBindBuffer(GL_ARRAY_BUFFER,
               vertex_buffer_obj); // Bind it to an array containing multiple VBOs.
  // Unbind our vertex objects to prevent further usage of these buffers.
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo::Delete()
{
  glDeleteBuffers(1, &vertex_buffer_obj);
}

#endif //GAME_OPENGL_VBO_H
