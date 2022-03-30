#version 120

attribute vec3 Pos;
attribute vec3 UV;
attribute vec3 Norm;

varying vec2 TexCoords;
varying vec3 WorldPos;
varying vec3 Normal;

uniform mat4 ProjMat = mat4(1.0);
uniform mat4 ViewMat = mat4(1.0);
uniform mat4 ModelMat = mat4(1.0);

void main() {
    WorldPos = vec3(ModelMat * vec4(Pos, 1.0));
    TexCoords = vec2(UV);
    Normal = mat3(ModelMat) * Norm;
    gl_Position = ProjMat * ViewMat * vec4(WorldPos, 1.0);
}