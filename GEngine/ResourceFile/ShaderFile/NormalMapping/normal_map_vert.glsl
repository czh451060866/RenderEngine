//
// Created by HongZh on 2022/03/14, 15:15:56
//

#version 120
attribute vec3 Pos;
attribute vec3 UV;
attribute vec3 Norm;
attribute vec3 Tangent;
attribute vec3 Bitangent;
uniform mat4 ProjMat;
uniform mat4 ViewMat;
uniform mat4 ModelMat;
uniform mat4 NormMat;

varying mat3 tbn;
varying vec3 pos;
varying vec3 uv;

void main() {
  vec4 model_pos = ModelMat * vec4(Pos, 1.0);
  vec3 T = (NormMat * vec4(Tangent, 1.0)).xyz;
  vec3 B = (NormMat * vec4(Bitangent, 1.0)).xyz;
  vec3 N = (NormMat * vec4(Norm, 1.0)).xyz;
  T = normalize(T);
  N = normalize(N);
  B = normalize(B);
  gl_Position = ProjMat * ViewMat * model_pos;
  tbn = mat3(T, B, N);
  pos = model_pos.xyz;
  uv = UV;
}