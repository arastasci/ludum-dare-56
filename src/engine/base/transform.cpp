#include "transform.h"
#include "gameobject.h"

transform::transform() : Component("transform")
{
	parent = nullptr;
}

transform::transform(Vector3 position, Vector3 scale, Vector3 rotation) : Component("transform")
{
	this->position = position;
	this->scale = scale;
	this->rotation = rotation;
	parent = nullptr;
}

transform::~transform()
{
}

void transform::Destroy()
{
	gameObject->Destroy();
}

void transform::DestroyImmediate()
{
	for (auto child : m_children)
	{
		child->gameObject->DestroyImmediate();
	}
	m_children.clear();

	if(parent != nullptr)
	{
		parent->m_children.erase(std::remove(parent->m_children.begin(), parent->m_children.end(), this), parent->m_children.end());
	}
}

void transform::AddChild(transform* child)
{
	if(child->parent != nullptr)
	{
		child->parent->m_children.erase(std::remove(child->parent->m_children.begin(), child->parent->m_children.end(), child), child->parent->m_children.end());
	}

	m_children.push_back(child);
	child->parent = this;
}

int transform::GetChildrenCount()
{
	return m_children.size();
}

transform* transform::GetChild(int index)
{
	return m_children[index];
}

transform* transform::GetParent()
{
	return parent;
}

void transform::SetParent(transform* t)
{
	if (parent != nullptr)
	{
		parent->m_children.erase(std::remove(parent->m_children.begin(), parent->m_children.end(), this), parent->m_children.end());
	}
	parent = t;
	if(t != nullptr)
	t->AddChild(this);
}
