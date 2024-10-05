#pragma once
#include "object.h"
#include "../render/Renderer.h"

class Scene;
class component;
class transform;

class gameobject : public object
{
public:
	gameobject(transform& t, RenderInfo& info);
	~gameobject();

	void AddComponent(component* comp);
	component* GetComponent(const char* name) const;
	void RemoveComponent(const char* name);
	void Update();

	transform* Transform;
	Scene* Scene;
	void Destroy();
	void DestroyImmediate() ;

	RenderInfo RenderInfo;
protected:
private:
	std::vector<component*> m_components;
};

