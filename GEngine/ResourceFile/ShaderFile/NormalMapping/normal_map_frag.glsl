//
// Created by HongZh on 2022/03/14, 15:16:04
//

#version 120

uniform sampler2D ColorTexture0; // normal map

uniform vec3 CameraPos;
uniform vec3 ObjectColor;
uniform vec3 LightColor;
uniform vec3 LightPos;
uniform vec3 LightDir = vec3(0.0);

varying vec3 uv;
varying vec3 pos;
varying mat3 tbn;

const vec3 BlinnPhongFactor = vec3(0.3, 0.4, 0.1);

vec3 BlinnPhongModel(vec3 norm) {
  // point light only
  float ambient = BlinnPhongFactor.x;
  float diffuse = BlinnPhongFactor.y;
  float specular = BlinnPhongFactor.z;

  // diffuse and specular
  vec3 l_dir;
  if (LightDir == vec3(0.0)) {
    l_dir = normalize(pos - LightPos);
  } else {
    l_dir = normalize(LightDir);
  }

  vec3 e_dir = normalize(CameraPos - pos);
  vec3 h_dir = normalize(-l_dir + e_dir); // halfway vector
  float diff = max(0.0, dot(-l_dir, norm));
  float spec = pow(max(dot(h_dir, norm), 0.0), 32.0);

  vec3 color =
      (ambient + diffuse * diff + specular * spec) * ObjectColor * LightColor;
  return color;
}

void main() {
  vec3 tbn_norm = texture2D(ColorTexture0, uv.xy).xyz;
  tbn_norm = tbn_norm * 2.0 - vec3(1.0);
  vec3 color = BlinnPhongModel(tbn * tbn_norm);
  gl_FragColor = vec4(color, 1.0);
}