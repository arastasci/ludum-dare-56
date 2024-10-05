#pragma once
#include <GLFW/glfw3.h>

#define KEY_COUNT 290
class KeyInput
{
public:
	static KeyInput& getInstance();
	KeyInput(KeyInput const&) = delete;
	void operator=(KeyInput const&) = delete;

	void update();
	void release();

	bool IsKeyPressed(int key);
	bool IsKeyReleased(int key);
	bool IsKeyRepeated(int key);
	enum KeyState
	{
		Idle,
		Pressed,
		Released,
		Repeat,
	};

private:
	KeyInput();
	~KeyInput();
	static void callback(
		GLFWwindow* window, int key, int scancode, int action, int mods);
	KeyState m_keys[KEY_COUNT];
};