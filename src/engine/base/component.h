#pragma once
#include "object.h"
#include "gameobject.h"

class component : public object
{
public:
	static void Destroy(object o);
	gameobject* GameObject;
protected:
	void Destroy() override;
	void DestroyImmediate() override;
};

