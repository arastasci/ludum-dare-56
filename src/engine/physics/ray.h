#pragma once
#include "../Vector3.h"
struct Ray
{
	Ray(Vector3 origin, Vector3 direction) 
	{
		this->origin = origin;
		this->direction = direction;
	}
	~Ray() = default;
	Vector3 GetPoint(float distance)
	{
				return origin + direction * distance;
	}
	Vector3 origin;
	Vector3 direction;

};

