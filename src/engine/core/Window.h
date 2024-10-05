#pragma once
#include "glad/glad.h"

#include <GLFW/glfw3.h>
class Window
{
public:
	static Window* GetInstance();
	void CreateWindow(int width, int height);
	int GetWidth();
	int GetHeight();
	bool ShouldClose();
	void SwapBuffers();
private:
	Window() = default;
	~Window() = default;

	static Window* instance;
	static void glViewPortSizeCallback(GLFWwindow* window, int width, int height);
	int m_width;
	int m_height;
	GLFWwindow* m_window;
};