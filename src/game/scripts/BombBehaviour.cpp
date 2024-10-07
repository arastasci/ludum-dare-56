#include "BombBehaviour.h"
#include "../prefab/Explosion.h"
#include "GridBehaviour.h"
#include "GameManagerBehaviour.h"
double BombBehaviour::m_duration = 3.0;

void BombBehaviour::Start()
{
    GameManagerBehaviour::GetInstance()->OnBombUsed();
    m_startTime = Timer::getInstance().getElapsedTime();
}

void BombBehaviour::Update()
{
    double dt = Timer::getInstance().getElapsedTime() - m_startTime;

    if (dt > m_duration)
    {
         transform  explosionTransform = {
            {gameObject->Transform->position.x, gameObject->Transform->position.y, 1.5f},
            {5.0, 5.0, 1.0},
            {0.0, 0.0, 0.0}
        };

        GameObject::Instantiate<Explosion>(explosionTransform);
        
        auto tileBehaviour = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();
        
        // neighbors indices 9x9
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                auto x = tileBehaviour->x + i;
                auto y = tileBehaviour->y + j;

                if (x >= 0 && x < 11 && y >= 0 && y < 11)
                {
                    auto tile = tileBehaviour->gridBehaviour->GetTileAt(x, y);

                    auto objects = tile->GetObjectsByType(GridObjectType::Agent);
                    for (auto object : objects)
                    {
                        tile->RemoveGridObject(object);
                        object->gameObject->Destroy();
                    }
                }
            }
        }

       

        gameObject->Destroy();
    }
}