#include "ParticleBehaviour.h"
#include "../../engine/base/renderproperties.h"
#include "../../engine/base/gameobject.h"

double ParticleBehaviour::m_appearAfter = 0.1f;

void ParticleBehaviour::Start()
{
    m_createdAt = Timer::getInstance().getElapsedTime();
    RenderProperties* rp = this->gameObject->GetComponent<RenderProperties>();

    rp->SetTextureCoords({11.0f, 11.0f});
}

void ParticleBehaviour::Update()
{
    if(Timer::getInstance().getElapsedTime() - m_createdAt > m_appearAfter)
    {
        RenderProperties* rp = this->gameObject->GetComponent<RenderProperties>();

        rp->SetTextureCoords({2.0f, 24.0f});
    }
}