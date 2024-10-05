#pragma once
#include "object.h"

class GameObject;

class Component : public Object
{
public:
	Component(const char* name);
	GameObject* GameObject;
};

