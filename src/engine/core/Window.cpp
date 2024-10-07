#include "Window.h"
#include <iostream>

Window* Window::instance = nullptr;
Window* Window::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Window();
	}
	return instance;
}

void Window::CreateWindow(int width, int height)
{
	m_width = width;
	m_height = height;

	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return;
	}

	m_window = glfwCreateWindow(width, height, "Whiny Preachers", NULL, NULL);
	if (!m_window)
	{
		glfwTerminate();
		std::cout << "Failed to create window" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_window);
	glfwSetWindowSizeCallback(m_window, glViewPortSizeCallback);
}

int Window::GetWidth()
{
	return m_width;
}

int Window::GetHeight()
{
	return m_height;
}

bool Window::ShouldClose()
{
	return glfwWindowShouldClose(m_window);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(m_window);
}

void Window::glViewPortSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	GetInstance()->m_width = width;
	GetInstance()->m_height = height;
}
