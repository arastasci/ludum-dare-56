#include "component.h"

Component::Component(const char* name) : Object(name)
{
    GameObject = nullptr; // the gameobject this Component is attached to will fill this in
}

