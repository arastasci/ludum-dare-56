#include "collider.h"
#include <glad/glad.h>
#include "../base/gameobject.h"
#include <glm/gtx/extended_min_max.hpp>
#include "screen_raycast_handler.h"
Collider::Collider() : Component("Collider")
{
}

Collider::Collider(Vector3 boundingBoxSize) : Component("Collider")
{
	m_boundingBoxSize = boundingBoxSize;
}

void Collider::OnCollision(Collider* other)
{
	// Do something

}

bool Collider::Intersects(Ray* ray, float& t)
{
    auto& r = *ray;
    Vector3 dirfrac;
    r.dir = r.dir.normalized();
    // r.dir is unit direction vector of ray
    dirfrac.x = 1.0f / r.dir.x;
    dirfrac.y = 1.0f / r.dir.y;
    dirfrac.z = 1.0f / r.dir.z;
    // lb is the corner of AABB with minimal coordinates - left bottom, rt is maximal corner
    // r.org is origin of ray
    auto pos = GameObject->Transform->position;
    Vector3 lb = pos - m_boundingBoxSize / 2.f;
    Vector3 rt = pos + m_boundingBoxSize / 2.f;

    float t1 = (lb.x - r.org.x) * dirfrac.x;
    float t2 = (rt.x - r.org.x) * dirfrac.x;
    float t3 = (lb.y - r.org.y) * dirfrac.y;
    float t4 = (rt.y - r.org.y) * dirfrac.y;
    float t5 = (lb.z - r.org.z) * dirfrac.z;
    float t6 = (rt.z - r.org.z) * dirfrac.z;

    
    float tmin = std::max(std::max(std::min(t1, t2), std::min(t3, t4)), std::min(t5, t6));
    float tmax = std::min(std::min(std::max(t1, t2), std::max(t3, t4)), std::max(t5, t6));
    // if tmax < 0, ray (line) is intersecting AABB, but the whole AABB is behind us
    if (tmax < 0)
    {
        t = tmax;
        return false;
    }

    // if tmin > tmax, ray doesn't intersect AABB
    if (tmin > tmax)
    {
        t = tmax;
        return false;
    }

    t = tmin;
    return true;
}

