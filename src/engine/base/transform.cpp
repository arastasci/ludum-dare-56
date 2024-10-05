#include "transform.h"
#include "gameobject.h"

transform::transform() : Component("transform")
{
	scale = Vector3(100, 100, 100);
	position = Vector3(0, 0, 0);
	parent = nullptr;
}

transform::~transform()
{
}

void transform::Destroy()
{
	GameObject->Destroy();
}

void transform::DestroyImmediate()
{
	for (auto child : m_children)
	{
		child->GameObject->DestroyImmediate();
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

