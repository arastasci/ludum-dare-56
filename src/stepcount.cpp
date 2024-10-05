#include "stepcount.h"
#include "engine/base/gameobject.h"
#include "engine/input/input.h"
#include "engine/timer.h"
#include "engine/physics/screen_raycast_handler.h"
stepcount::stepcount() : Behaviour("stepcount")
{
}

void stepcount::Update()
{
	//GameObject->Transform->position.x += 0.01f * Timer::getInstance().getDeltaTime();
	if (KeyInput::getInstance().IsKeyPressed(GLFW_KEY_W))
	{
		GameObject->Transform->position.y += 1.f * Timer::getInstance().getDeltaTime();
	}
	if (MouseInput::getInstance().IsButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
	{
		//GameObject->Transform->position.z += 0.01f;
		auto mousePosition = MouseInput::getInstance().mousePosition;
		ScreenRaycastHandler::GetInstance().Raycast(mousePosition.x, mousePosition.y);
	}
}
