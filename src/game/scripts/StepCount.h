#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/transform.h"

class StepCount : public Behaviour
{
public:
	StepCount();
	void Update() override;
};
