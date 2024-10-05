#include "screen_raycast_handler.h"
#include "ray.h"
#include "../../constants.h"
#include "cmath"
#include <GLFW/glfw3.h>
#include "../core/Window.h"
ScreenRaycastHandler::ScreenRaycastHandler()
{
}

ScreenRaycastHandler& ScreenRaycastHandler::GetInstance()
{
    static ScreenRaycastHandler instance;
	return instance;
}

void ScreenRaycastHandler::Raycast(double xpos, double ypos)
{
    float windowWidth = Window::GetInstance()->GetWidth();
    float windowHeight = Window::GetInstance()->GetHeight();
    
    Vector3 camDirection = Vector3(0, 0, 1);
    float x = (2.0f * xpos / (float)windowWidth - 1) * (ORTHO_WIDTH);
    float y = (2.0f * ypos / (float)windowHeight - 1) * (ORTHO_HEIGHT);

    Vector3 origin = Vector3(0, 0, -3) + Vector3(1, 0, 0) * x + Vector3(0, 1, 0) * y;
    Ray* ray = new Ray(origin, camDirection);
   
    Collider* collidedCollider = nullptr;
    float minT = std::numeric_limits<float>::max();
	for (int i = 0; i < Colliders->size(); i++)
	{
        float t;
        if ((*Colliders)[i] != nullptr && (*Colliders)[i]->Intersects(ray, t))
        {
            if (minT > t)
            {
                minT = t;
                collidedCollider = (*Colliders)[i];
            }
		}
	}
    if (collidedCollider != nullptr)
    {
		collidedCollider->OnRaycastHit(collidedCollider);
	}
}
