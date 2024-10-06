#include "stepcount.h"
#include "../../engine/base/gameobject.h"
#include "../../engine/input/input.h"
#include "../../engine/timer.h"
#include "../../engine/physics/screen_raycast_handler.h"

StepCount::StepCount() : Behaviour("StepCount")
{
}

void StepCount::Update()
{
	//GameObject->Transform->position.x += 0.01f * Timer::getInstance().getDeltaTime();
	if (KeyInput::getInstance().IsKeyPressed(GLFW_KEY_W))
	{
		gameObject->Transform->position.y += 1.f * Timer::getInstance().getDeltaTime();
	}
	
	//GameObject->Transform->position.z += 0.01f;
	auto mousePosition = MouseInput::getInstance().mousePosition;
	ScreenRaycastHandler::GetInstance().Raycast(mousePosition.x, mousePosition.y);
}
