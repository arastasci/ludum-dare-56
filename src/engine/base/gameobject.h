#pragma once
#include "object.h"
#include "component.h"
#include "transform.h"
#include "Scene.h"
class gameobject : public object
{
public:
	gameobject();
	~gameobject();
	gameobject(transform& t);
	
	void AddComponent(component* comp);
	component* GetComponent(const char* name) const;
	void RemoveComponent(const char* name);
	void Update();

	transform* Transform;
	Scene* Scene;
	void Destroy();
	void DestroyImmediate() override;
protected:
private:
	std::vector<component*> m_components;
};

