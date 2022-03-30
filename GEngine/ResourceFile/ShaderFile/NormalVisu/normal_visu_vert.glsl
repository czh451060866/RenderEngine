//
// Created by HongZh on 2022/02/20, 15:37:32
//

#version 120

attribute vec3 Pos;
attribute vec3 UV;
attribute vec3 Norm;
uniform mat4 ProjMat;
uniform mat4 ViewMat;
uniform mat4 ModelMat;
uniform mat4 NormMat;

varying vec3 norm;

void main() {
  vec4 model_pos = ModelMat * vec4(Pos, 1.0);
  vec4 model_norm = NormMat * vec4(Norm, 1.0);
  gl_Position = ProjMat * ViewMat * model_pos;
  norm = normalize(model_norm.xyz);
}
