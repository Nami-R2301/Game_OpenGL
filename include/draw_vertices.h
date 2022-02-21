//
// Created by nami on 2022-02-20.
//

#ifndef GAME_OPENGL_DRAW_VERTICES_H
#define GAME_OPENGL_DRAW_VERTICES_H
#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>
#include <cmath>

// Vertex to pass on to our opengl vertex shaders.
typedef struct gl_vertex_s
{
  GLfloat x_pos = 0.0f;
  GLfloat y_pos = 0.0f;
  GLfloat z_pos = 0.0f;
} gl_vertex_t;

typedef struct gl_object_drawn_s
{
  GLuint vertex_shader = 0;
  GLuint fragment_shader = 0;
  GLuint vertex_array_obj = 0;
  GLuint vertex_buffer_obj = 0;
  GLuint shader_program = 0;
} gl_object_drawn_t;

gl_object_drawn_t draw(gl_vertex_t vertices[]);


#endif //GAME_OPENGL_DRAW_VERTICES_H
