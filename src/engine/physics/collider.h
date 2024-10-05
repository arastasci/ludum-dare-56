#pragma once
#include "../base/component.h"
#include "../Vector3.h"
#include "../render/shader.h"
#include "ray.h"
class Collider : public Component
{
public:
	Collider();
	Collider(Vector3 boundingBoxCenter);
	~Collider() = default;
	void OnRaycastHit(Collider* other);
	bool Intersects(Ray* ray, float& t);

private:
	Vector3 m_boundingBoxSize;
};

