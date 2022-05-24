#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>

#pragma comment(lib,"opengl32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    float Kx = 0, Ky = 0;
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        glEnable(GL_BLEND);

        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001) {
            Kx -= 0.01f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001) {
            Kx += 0.01f;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001) {
            Ky += 0.01f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001) {
            Ky -= 0.01f;
        }

        glClearColor(0.7f, 0.7f, 0.7f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLE_STRIP);

        glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.1f);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(0.6f, 0.1f);
        glEnd();

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glBegin(GL_TRIANGLE_STRIP);

        glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
        glVertex2f(Kx, Ky);
        glVertex2f(Kx+0.1f, Ky);
        glVertex2f(Kx, Ky+0.1f);
        glVertex2f(Kx + 0.1f, Ky + 0.1f);
        glEnd();

        glFlush();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}