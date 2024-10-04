#pragma once
#include "object.h"

class Scene;
class component;
class transform;

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
	void DestroyImmediate() ;
protected:
private:
	std::vector<component*> m_components;
};

