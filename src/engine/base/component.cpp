#include "component.h"

Component::Component(const char* name) : Object(name)
{
    gameObject = nullptr; // the gameobject this Component is attached to will fill this in
}

