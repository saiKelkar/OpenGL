#version 330 core

layout(location=0) in vec3 aPos;
layout(location=1) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 FragPos;

void main() {
    gl_Position = vec4(aPos, 1.0);
    TexCoord = aTexCoord;
    FragPos = aPos;
}