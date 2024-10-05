#pragma once
#include "object.h"
#include "gameobject.h"

class Component : public Object
{
public:
	Component(const char* name);
	GameObject* GameObject;
};

