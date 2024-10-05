#pragma once
#include "../Vector3.h"
struct Ray
{
	Ray(Vector3 origin, Vector3 direction) 
	{
		this->org = origin;
		this->dir = direction;
	}
	~Ray() = default;
	Vector3 GetPoint(float distance)
	{
				return org + dir * distance;
	}
	Vector3 org;
	Vector3 dir;

};

