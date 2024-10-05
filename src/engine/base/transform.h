#pragma once
#include "component.h"
#include "../Vector3.h"
class transform : public Component
{
public:
	transform();
	~transform();
	void Destroy() override;
	void DestroyImmediate() override;
	int GetChildrenCount();
	transform* GetParent();
	transform* GetChild(int index);
	void AddChild(transform* child);
	Vector3 position = {0,0,0};
	Vector3 scale = {1,1,1};
	Vector3 rotation = {0,0,0};
private:
	transform* parent;

	std::vector<transform*> m_children;

};

