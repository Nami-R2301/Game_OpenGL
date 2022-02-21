//
// Created by nami on 2022-02-20.
//
#include "../include/draw_vertices.h"

// Vertex Shader source code
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "uniform float size;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(size * aPos.x, size * aPos.y, size * aPos.z, 1.0);\n"
                                 "}\0";
//Fragment Shader source code
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "uniform vec4 color;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = color;\n"
                                   "}\n\0";


gl_object_drawn_t draw(gl_vertex_t vertices[])
{
  gl_object_drawn_t object_drawn;

  // Create Shaders for our vertex buffer object (VBO).
  object_drawn.vertex_shader = glCreateShader(GL_VERTEX_SHADER);

  //Set the source code in shader to the source code in the array of strings specified by string.
  glShaderSource(object_drawn.vertex_shader, 1, &vertexShaderSource, nullptr);
  glCompileShader(object_drawn.vertex_shader);
  object_drawn.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(object_drawn.fragment_shader, 1, &fragmentShaderSource, nullptr);
  // Compile the shaders into machine code to pass on to the GPU.
  glCompileShader(object_drawn.fragment_shader);

  // Set our shader program to attach our created shader to it (link source codes like '#include').
  object_drawn.shader_program = glCreateProgram(); // Creates an empty object program (.o).
  glAttachShader(object_drawn.shader_program, object_drawn.vertex_shader);
  glAttachShader(object_drawn.shader_program, object_drawn.fragment_shader);

  // Links all source codes (shaders) in the program given as argument, creating the executable.
  glLinkProgram(object_drawn.shader_program);

  // Delete the shaders since they have been compiled and linked in the program.
  glDeleteShader(object_drawn.vertex_shader);
  glDeleteShader(object_drawn.fragment_shader);

  // Create vertex objects to contain and wrap our data to transfer data following opengl conventions.
  glGenVertexArrays(1, &object_drawn.vertex_array_obj);
  glGenBuffers(1, &object_drawn.vertex_buffer_obj); // Create empty buffer for our vertex data.
  // Make the VAO the current Vertex Array Object by binding it
  glBindVertexArray(object_drawn.vertex_array_obj);
  glBindBuffer(GL_ARRAY_BUFFER,
               object_drawn.vertex_buffer_obj); // Bind it to an array containing multiple VBOs.
  glBufferData(GL_ARRAY_BUFFER, sizeof(*vertices), vertices, GL_STATIC_DRAW); // Specify the data.

  // Specify the attribute of the vertex data to create a vertex attribute array for rendering data.
  // Arguments serve to specify the number, type and stride (number of bytes to 'hop' between data).
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
  glEnableVertexAttribArray(
      0); // Enable our vertex attribute array and set the initial index cursor.

  // Unbind our vertex objects to prevent further usage of these buffers.
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  return object_drawn;
}
