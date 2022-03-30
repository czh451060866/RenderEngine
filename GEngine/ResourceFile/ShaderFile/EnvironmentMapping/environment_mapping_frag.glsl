//
// Created by HongZh on 2022/03/04, 15:03:14
//

#version 120

uniform samplerCube CubeMapTexture0;
uniform vec3 CameraPos;
varying vec3 pos;
varying vec3 norm;

uniform float Lod = 0.0;

void main() {
  vec3 eye = normalize(pos - CameraPos);
  vec3 reflection = eye + 2 * abs(dot(eye, norm)) * norm;
  vec4 color = textureCube(CubeMapTexture0, reflection, Lod);
  gl_FragColor = color;
}