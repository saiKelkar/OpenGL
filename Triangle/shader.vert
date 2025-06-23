// uses GLSL version 3.30
// Takes input aPos from location 0
// Outputs gl_Position to clip space

#version 330 core
layout (location = 0) in vec3 aPos;

void main() {
    gl_Position = vec4(aPos, 1.0);
}