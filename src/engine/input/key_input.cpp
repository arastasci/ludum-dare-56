#include "key_input.h"

KeyInput::KeyInput()
{
	update();
	glfwSetKeyCallback(glfwGetCurrentContext(), callback);
}

KeyInput::~KeyInput()
{
}

KeyInput& KeyInput::getInstance()
{
	static KeyInput instance;
	return instance;
}

void KeyInput::update()
{
	for (int i = 0; i < KEY_COUNT; i++)
	{
		m_keys[i] = KeyState::Idle;
	}
}

bool KeyInput::IsKeyPressed(int key)
{
	return m_keys[key] == KeyState::Pressed;
}

bool KeyInput::IsKeyReleased(int key)
{
	return m_keys[key] == KeyState::Released;
}


bool KeyInput::IsKeyRepeated(int key)
{
	return m_keys[key] == KeyState::Repeat;
}


void KeyInput::callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyInput& input = KeyInput::getInstance();
	if (action == GLFW_PRESS)
	{
		input.m_keys[key] = KeyState::Pressed;
	}
	else if (action == GLFW_RELEASE)
	{
		input.m_keys[key] = KeyState::Released;
	}
	else if (action == GLFW_REPEAT)
	{
		input.m_keys[key] = KeyState::Repeat;
	}
}

