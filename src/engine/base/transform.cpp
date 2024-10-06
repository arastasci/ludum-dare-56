#include "transform.h"
#include "gameobject.h"

transform::transform() : Component("transform")
{
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
}

void transform::AddChild(transform* child)
{
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

