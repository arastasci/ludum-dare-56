#include "object.h"

object::object()
{

}

void object::setWillBeDestroyed()
{
	m_WillBeDestroyed = true;
}

bool object::GetWillBeDestroyed() const
{
	return m_WillBeDestroyed;
}

void object::Destroy(object* o)
{
	o->setWillBeDestroyed();
}

void object::Destroy()
{
}

void object::DestroyImmediate()
{
}