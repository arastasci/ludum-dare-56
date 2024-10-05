#include "stepcount.h"
#include "engine/base/gameobject.h"

stepcount::stepcount() : Behaviour("stepcount")
{
}

void stepcount::Update()
{
	GameObject->Transform->position.x += 0.01f;
}
