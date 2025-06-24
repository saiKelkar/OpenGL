// uses GLSL version 3.30
// Takes input aPos from location 0
// Outputs gl_Position to clip space

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 vertexColor; // output to fragment shader

void main() {
    gl_Position = vec4(aPos, 1.0);
    vertexColor = aColor; // pass color to fragment shader
}