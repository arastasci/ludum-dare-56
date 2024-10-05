#include "screen_raycast_handler.h"
#include "ray.h"
#include "../../constants.h"
#include "cmath"
#include <GLFW/glfw3.h>
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
    int windowWidth, windowHeight;
    glfwGetWindowSize(glfwGetCurrentContext(), &windowWidth, &windowHeight);
    Vector3 relative(
        xpos / windowWidth - 0.5f, 1 -
       ypos / windowHeight - 0.5f, 0
    );
    auto orthographic = false;
    Ray* ray;
 /*   if (!orthographic)*/ 
        // Angle in radians from the view axis
        // to the top plane of the view pyramid.
        
        auto aspect = static_cast<float>(windowWidth) / static_cast<float>(windowHeight);

        //auto fov = 45.0f;
        //float verticalAngle = 0.5f * MATH_DEG2RAD * fov; // fov / 2

        //// World space height of the view pyramid
        //// measured at 1 m depth from the camera.
        //float worldHeight = 2.f * tanf(verticalAngle);

        //// Convert relative position to world units.
        //Vector3 worldUnits = relative * worldHeight;
        //worldUnits.x *= aspect;
        //worldUnits.z = 1;

        //// Rotate to match camera orientation.
        //
        //auto glmDirection = glm::quatLookAt(glm::vec3(0, 0, -1), glm::vec3(0,1,0)) * worldUnits.toGlmVec3();
        //Vector3 direction = Vector3(glmDirection.x, glmDirection.y, glmDirection.z);

        //// Output a ray from camera position, along this direction.
        //ray = new Ray(Vector3(0,0, -3), direction);
        Vector3 camDirection = Vector3(0, 0, 1);
        float x = (2.0f * xpos / (float)windowWidth - 1) * ( aspect * 2.f / 2.f);
        float y = (2.0f * ypos / (float)windowHeight - 1) * (2.f / 2.f);

        Vector3 origin = Vector3(0, 0, -3) + Vector3(1, 0, 0) * x + Vector3(0, 1, 0) * y;
        ray = new Ray(origin, camDirection);
    
    //else {
    //    // Scale using half-height of camera.
    //    Vector3 worldUnits = relative * orthographicSize * 2f;
    //    worldUnits.x *= aspect;

    //    // Orient and position to match camera transform.
    //    Vector3 origin = transform.rotation * worldUnits;
    //    origin += transform.position;

    //    // Output a ray from this point, along camera's axis.
    //    return new Ray(origin, transform.forward);
    //}
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
		collidedCollider->OnCollision(collidedCollider);
	}
}
