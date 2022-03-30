//
// Created by HongZh on 2022/03/12, 16:57:10
//

#version 120
attribute vec3 Pos;
attribute vec3 UV;
attribute vec3 Norm;
uniform mat4 ProjMat;
uniform mat4 ViewMat;
uniform mat4 ModelMat;
uniform mat4 NormMat;

uniform sampler2D ColorTexture0;
const float DFactor = 0.1;

varying vec3 pos;
varying vec3 norm;

void main() {
  vec4 model_pos = ModelMat * vec4(Pos, 1.0);
  vec4 model_norm = NormMat * vec4(Norm, 1.0);

  // compute the offset
  vec4 color = texture2D(ColorTexture0, UV.xy);
  float offset = ((color.r + color.g + color.b) / 3.0 - 0.5) * DFactor;
  norm = normalize(model_norm.xyz);
  vec4 modified_pos = vec4(model_pos.xyz + offset * norm, 1.0);

  gl_Position = ProjMat * ViewMat * modified_pos;
  pos = modified_pos.xyz;
}