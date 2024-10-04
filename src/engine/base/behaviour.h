#pragma once
#include "object.h"
#include "component.h"
class Behaviour : public component
{
protected:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void OnDestroy() = 0;

};

