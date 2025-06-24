#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
in vec3 FragPos;

uniform sampler2D ourTexture;

void main() {
    vec4 texColor = texture(ourTexture, TexCoord);
    vec3 gradientColor = mix(vec3(1.0, 0.0, 0.0), vec3(1.0, 1.0, 0.0), TexCoord.y);
    vec4 finalColor = vec4(gradientColor, 1.0) * texColor;
    FragColor = finalColor;
}