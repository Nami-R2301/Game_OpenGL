//
// Created by nami on 2022-02-23.
//

#ifndef GAME_OPENGL_SHADERS_H
#define GAME_OPENGL_SHADERS_H
#include <GLES3/gl3.h>
#include <vector>
using namespace std;


class shaders {

  shaders();
  void add(GLuint, void*);
  GLuint* get_shaders();
  void Delete();

  std::vector<GLuint> shaders_array;

};

shaders::shaders()
{
  shaders_array.resize(4);
}

void shaders::add(GLuint shader, void* type)
{
  shaders_array.push_back(shader);
}

void shaders::Delete()
{
  for(GLuint shader : shaders_array)
  {
    shader.Delete();
  }
}

#endif //GAME_OPENGL_SHADERS_H
