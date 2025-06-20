// GLAD must come first! Loads all OpenGL functions
#include <glad/glad.h>
// GLFW manages windows, inputs, and OpenGL context
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // glfwInit() <-- sets up everything GLFW needs (like OpenGL context support, window creation)
    // if it fails, we exit early
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!\n";
        return -1;
    }

    // Creates a 640 x 480 window with the title "GLFW in WSL"
    // last two nullptr:
    // (1) No specific monitor (so it's windowed, not fullscreen)
    // (2) No OpenGL context sharing with another window
    GLFWwindow* window = glfwCreateWindow(640, 480, "GLFW in WSL", nullptr, nullptr);
    if (!window) {
        std::cerr << "Window creation failed!\n";
        glfwTerminate();
        return -1;
    }

    // Tells OpenGL to use this window as the rendering target
    glfwMakeContextCurrent(window);

    // Initialize GLAD by asking GLFW for the actual OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!\n";
        return -1;
    }

    // Sets the color used when clearing the screen each frame
    glClearColor(0.5f, 0.5f, 0.0f, 1.0f); // olive green and 1.0 is fully opaque

    // Game loop / Render loop
    // Runs until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Fill the screen with the color set in glClearColor()
        glClear(GL_COLOR_BUFFER_BIT);
        // OpenGL uses double buffering
        // Shows the frame we just rendered, and starts working on the next one behind the scenes
        glfwSwapBuffers(window);
        // Handles keyboard / mouse / window input; Window would freeze without this
        glfwPollEvents();
    }

    // Free the memory for the window
    // Shut down GLFW safely
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}