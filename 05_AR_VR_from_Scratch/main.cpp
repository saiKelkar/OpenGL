#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>
#include <iostream>

// Window size
const int WIDTH = 800;
const int HEIGHT = 600;

int main() {
    cv::VideoCapture cap(0);
    if(!cap.isOpened()) {
        std::cerr << "Failed to open webcam.\n";
        return -1;
    }

    if(!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Webcam", nullptr, nullptr);
    if(!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex2f( 0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex2f( 0.5f,  0.5f);
            glColor3f(1.0f, 1.0f, 0.0f); glVertex2f(-0.5f,  0.5f);
        glEnd();

        cv::Mat frame;
        cap >> frame;
        glfwSwapBuffers(window);
    }

    cap.release();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}