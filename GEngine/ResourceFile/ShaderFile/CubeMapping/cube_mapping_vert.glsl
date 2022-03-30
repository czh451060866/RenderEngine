//
// Created by HongZh on 2022/03/04, 14:49:27
//

#version 120

attribute vec3 Pos;
uniform mat4 ProjMat;
uniform mat4 ViewMat;
uniform mat4 ModelMat;

varying vec3 uv;

void main() {
  vec4 model_pos = ModelMat * vec4(Pos, 1.0);
  gl_Position = ProjMat * ViewMat * model_pos;
  uv = model_pos.xyz;
}