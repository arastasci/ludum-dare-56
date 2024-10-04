#include "component.h"

void component::Destroy(object o)
{
    o.Destroy();
}

void component::Destroy()
{
}

void component::DestroyImmediate()
{
}