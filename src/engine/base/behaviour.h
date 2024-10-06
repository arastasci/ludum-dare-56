#pragma once
#include "component.h"
class Behaviour : public Component
{
public:
	Behaviour(const char* name);
	virtual void Start();
	virtual void Awake();
	virtual void OnDestroy();
	virtual void Update();
	virtual void OnRaycastHit();
};

