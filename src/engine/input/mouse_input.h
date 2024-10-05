#pragma once
#include "../Vector3.h"
#include <GLFW/glfw3.h>
#define MOUSE_BUTTON_COUNT 3
class MouseInput
{
public:
	static MouseInput& getInstance();
	MouseInput(MouseInput const&) = delete;
	void operator=(MouseInput const&) = delete;

	void update();
	void release();

	Vector3 mousePosition;
	Vector3 mouseDelta;
	bool IsButtonPressed(int button);
	bool IsButtonReleased(int button);
	bool IsButtonRepeated(int button);
private:
	MouseInput();
	~MouseInput();
	static void mouseButtonCallback(
		GLFWwindow* window, int button, int action, int mods);
	static void mousePositionCallback(
		GLFWwindow* window, double xpos, double ypos);
	enum KeyState
	{
		Idle,
		Pressed,
		Released,
		Repeat,
	};
	KeyState m_buttons[MOUSE_BUTTON_COUNT];
};