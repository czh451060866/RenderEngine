//
// Created by HongZh on 2022/03/04, 14:53:06
//

#version 120

uniform samplerCube CubeMapTexture0;
varying vec3 uv;

void main() { gl_FragColor = textureCube(CubeMapTexture0, uv); }