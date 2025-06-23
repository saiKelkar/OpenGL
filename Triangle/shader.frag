// Sets the output pixel color to orange
// This shader is run once per pixel that the triangle covers

#version 330 core
out vec4 FragColor;

void main() {
    FragColor = vec4(1.0, 0.5, 0.2, 1.0); // orange
}