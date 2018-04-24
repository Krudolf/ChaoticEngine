
#include <../include/CEskybox.hpp>
#include <iostream>
#include "stb_image.h"

//Constructor
CESkybox::CESkybox() : CEEntity(){}


//Destructor
CESkybox::~CESkybox(){}

void CESkybox::makeSkyCube(){
  float x = 10.0f;
  float points[] = {
    -x,  x, -x,
    -x, -x, -x,
     x, -x, -x,
     x, -x, -x,
     x,  x, -x,
    -x,  x, -x,
    
    -x, -x,  x,
    -x, -x, -x,
    -x,  x, -x,
    -x,  x, -x,
    -x,  x,  x,
    -x, -x,  x,
    
     x, -x, -x,
     x, -x,  x,
     x,  x,  x,
     x,  x,  x,
     x,  x, -x,
     x, -x, -x,
     
    -x, -x,  x,
    -x,  x,  x,
     x,  x,  x,
     x,  x,  x,
     x, -x,  x,
    -x, -x,  x,
    
    -x,  x, -x,
     x,  x, -x,
     x,  x,  x,
     x,  x,  x,
    -x,  x,  x,
    -x,  x, -x,
    
    -x, -x, -x,
    -x, -x,  x,
     x, -x, -x,
     x, -x, -x,
    -x, -x,  x,
     x, -x,  x
  };
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, 3 * 36 * sizeof(float), &points, GL_STATIC_DRAW);

  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void CESkybox::create_cube_map(const char* p_textures[6], GLuint* p_tex_cube) {
  //0-> front, 1->back, 2->top, 3->bottom, 4->left, 5->right
  // generate a cube-map texture to hold all the sides
  glActiveTexture(GL_TEXTURE0);
  glGenTextures(1, p_tex_cube);
  
  // load each image and copy into a side of the cube-map texture
  load_cube_map_side(*p_tex_cube, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, p_textures[0]);
  load_cube_map_side(*p_tex_cube, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, p_textures[1]);
  load_cube_map_side(*p_tex_cube, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, p_textures[2]);
  load_cube_map_side(*p_tex_cube, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, p_textures[3]);
  load_cube_map_side(*p_tex_cube, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, p_textures[4]);
  load_cube_map_side(*p_tex_cube, GL_TEXTURE_CUBE_MAP_POSITIVE_X, p_textures[5]);
  // format cube map texture
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

bool CESkybox::load_cube_map_side(GLuint p_texture, GLenum p_side_target, const char* p_file_name) {
  glBindTexture(GL_TEXTURE_CUBE_MAP, p_texture);

  int x, y, n;
  int force_channels = 4;
  unsigned char*  image_data = stbi_load(p_file_name, &x, &y, &n, force_channels);

  if (!image_data) {
    fprintf(stderr, "ERROR: could not load %s\n", p_file_name);
    return false;
  }
  // non-power-of-2 dimensions check
  if ((x & (x - 1)) != 0 || (y & (y - 1)) != 0) {
    fprintf(stderr,
      "WARNING: image %s is not power-of-2 dimensions\n",
      p_file_name);
  }
  
  // copy image data into 'target' side of cube map
  glTexImage2D(p_side_target, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
  free(image_data);
  return true;
}

void CESkybox::beginDraw(){
}

void CESkybox::endDraw(){}