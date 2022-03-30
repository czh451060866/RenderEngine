//
// Created by HongZh on 2022/02/20, 15:34:26
//

#version 120

varying vec3 norm;

void main() { gl_FragColor = vec4(norm, 1.0); }