#include "mouse_input.h"

MouseInput::MouseInput()
{
	update();
	glfwSetMouseButtonCallback(glfwGetCurrentContext(), mouseButtonCallback);
	glfwSetCursorPosCallback(glfwGetCurrentContext(), mousePositionCallback);
}

MouseInput::~MouseInput()
{
}

MouseInput& MouseInput::getInstance()
{
	static MouseInput instance;
	return instance;
}

void MouseInput::update()
{
	mouseDelta = Vector3(0, 0, 0);
	for (int i = 0; i < MOUSE_BUTTON_COUNT; i++)
	{
		m_buttons[i] = KeyState::Idle;
	}
}

bool MouseInput::IsButtonPressed(int button)
{
	return m_buttons[button] == KeyState::Pressed;
}

bool MouseInput::IsButtonReleased(int button)
{
	return m_buttons[button] == KeyState::Released;
}

bool MouseInput::IsButtonRepeated(int button)
{
	return m_buttons[button] == KeyState::Repeat;
}

void MouseInput::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	MouseInput& input = MouseInput::getInstance();
	if (action == GLFW_PRESS)
	{
		input.m_buttons[button] = KeyState::Pressed;
	}
	else if (action == GLFW_RELEASE)
	{
		input.m_buttons[button] = KeyState::Released;
	}
}

void MouseInput::mousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	MouseInput& input = MouseInput::getInstance();
	input.mouseDelta = Vector3(xpos - input.mousePosition.x, ypos - input.mousePosition.y, 0);
	input.mousePosition = Vector3(xpos, ypos, 0);
}