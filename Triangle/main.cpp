#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
// fstream and sstream -- used to read shader files
#include <fstream>
#include <sstream>
#include <string>

// shader file loader function
// reads the content of a file and returns it as a string
// used to load .vert and .frag shader source code
std::string loadShader(const char* path) {
    std::ifstream file(path);
    std::stringstream buf;
    buf << file.rdbuf();
    return buf.str();
}

int main() {
    // Init GLFW
    if(!glfwInit()) {
        std::cerr << "Failed to init GLFW\n";
        return -1;
    }

    // OpenGL version 3.3 core profile
    // Core profile disables legacy OpenGL (e.g., glBegin / glEnd), forcing modern pipeline use
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", NULL, NULL);
    if(!window) {
        std::cerr << "Failed to init GLAD\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    // Load GLAD
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // Triangle Data
    // Define 3 vertices -- normalized device coordinates, centered in the screen
    float vertices[] = {
        0.0f, 0.5f, 0.0f, // top
        -0.5f, -0.5f, 0.0f, // left
        0.5f, -0.5f, 0.0f //right
    };

    // Create VAO and VBO, send data to GPU
    // VAO = vertex array object -- stores all the settings related to vertex input
    // VBO = vertex buffer object -- holds raw vertex data
    // glBufferData -- sends vertex data to GPU
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO); // VAO first
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Layout (location = 0)
    // Says "attribute location 0 should take 3 floats (x, y, z) per vertex from the buffer"
    // Tells GPU how to interpret each chunk of byte from the vertex buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Load and Compile Shaders
    std::string vertexCode = loadShader("shader.vert");
    std::string fragmentCode = loadShader("shader.frag");
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // Read the shader code from the external files
    // Get them compiled on the GPU and will be linked into a shader program

    // Vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    // Fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    // Shader program
    // shaderProgram -- used to render geometry with our custom logic
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Clean up shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // background color
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3); // draw 3 vertices

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}