//
// Created by HongZh on 2022/02/20, 15:34:26
//

#version 120

uniform vec3 ObjectColor;

void main() {
    gl_FragColor = vec4(ObjectColor, 1.0);
}