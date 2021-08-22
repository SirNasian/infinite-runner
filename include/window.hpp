#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "./renderer.hpp"

GLFWwindow* InitWindow();
int DisplayWindow(GLFWwindow *window, Renderer *renderer);
