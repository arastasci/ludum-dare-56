#pragma once
#include "collider.h"

class ScreenRaycastHandler
{
public:
	static ScreenRaycastHandler& GetInstance();
	void Raycast(double xpos, double ypos);
	std::vector<Collider*>* Colliders;
private:
	ScreenRaycastHandler();

};