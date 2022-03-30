//
// Created by HongZh on 2022/03/04, 14:59:28
//

#version 120
attribute vec3 Pos;
attribute vec3 Norm;
uniform mat4 ProjMat;
uniform mat4 ViewMat;
uniform mat4 ModelMat;

varying vec3 pos;
varying vec3 norm;

void main() {
  vec4 model_pos = ModelMat * vec4(Pos, 1.0);
  vec4 model_norm = ModelMat * vec4(Norm, 1.0);
  gl_Position = ProjMat * ViewMat * model_pos;
  pos = model_pos.xyz;
  norm = normalize(model_norm.xyz);
}