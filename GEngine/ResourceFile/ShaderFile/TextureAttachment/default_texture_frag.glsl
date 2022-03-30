//
// Created by HongZh on 2022/02/20, 15:34:26
//

#version 120

uniform sampler2D ColorTexture0;
varying vec3 uv;

void main() {
  vec4 color = texture2D(ColorTexture0, uv.xy);
  gl_FragColor = vec4(color.rgb, 1.0);
}