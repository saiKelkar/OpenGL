// Sets the output pixel color to orange
// This shader is run once per pixel that the triangle covers

#version 330 core

in vec3 vertexColor; // from vertex shader
out vec4 FragColor;

void main() {
    FragColor = vec4(vertexColor, 1.0); // just using it
}