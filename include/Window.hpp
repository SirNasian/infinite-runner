#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "./GameController.hpp"

GLFWwindow* InitWindow();
int DisplayWindow(GLFWwindow *window, GameController *controller);
