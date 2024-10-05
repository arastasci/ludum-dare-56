#pragma once
#include "engine/base/behaviour.h"
#include "engine/base/transform.h"

class stepcount : public Behaviour
{
public:
	stepcount();
	void Update() override;
};

