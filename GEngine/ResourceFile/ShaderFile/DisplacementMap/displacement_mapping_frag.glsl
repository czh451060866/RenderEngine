//
// Created by HongZh on 2022/03/12, 17:09:36
//

#version 120

uniform vec3 CameraPos;
uniform vec3 ObjectColor;
uniform vec3 BlinnPhongFactor;
uniform vec3 LightColor;
uniform vec3 LightPos;
uniform vec3 LightDir;
uniform sampler2D texture0;

varying vec3 pos;
varying vec3 norm;

void main() {
  // point light only
  float ambient = BlinnPhongFactor.x;
  float diffuse = BlinnPhongFactor.y;
//   float specular = BlinnPhongFactor.z;

  // diffuse and specular
  vec3 l_dir;
  if(LightDir == vec3(0.0)){
    l_dir = normalize(pos - LightPos);
  }
  else{
    l_dir = normalize(LightDir);
  }

  vec3 e_dir = normalize(CameraPos - pos);
  vec3 h_dir = normalize(-l_dir + e_dir); // halfway vector
  float diff = max(0.0, dot(-l_dir, norm));
//   float spec = pow(max(dot(h_dir, norm), 0.0), 32.0);

  vec3 color =
      (ambient + diffuse * diff ) * ObjectColor * LightColor;
  gl_FragColor = vec4(color, 1.0);
}