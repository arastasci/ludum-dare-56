#pragma once
#include "component.h"
class Behaviour : public Component
{
public:
	Behaviour(const char* name);
	virtual void Start();
	virtual void OnDestroy();
	virtual void Update();
};

