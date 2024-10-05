#include "object.h"

Object::Object()
{

}

Object::Object(const char* name)
{
	this->name = name;
}

void Object::setWillBeDestroyed()
{
	m_WillBeDestroyed = true;
}

bool Object::GetWillBeDestroyed() const
{
	return m_WillBeDestroyed;
}

void Object::Destroy()
{
	setWillBeDestroyed();
}

void Object::DestroyImmediate()
{
}