#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/transform.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "GridObjectBehaviour.h"
#include <vector>
#include "AgentBehaviour.h"
class GridBehaviour : public Behaviour {
    public:
        GridBehaviour() : Behaviour("GridBehaviour") {};
        void Awake();
        void Start();
        void Update();
        void OnDestroy();
        TileBehaviour* GetTileAt(int x, int y);
        std::vector <std::pair<int, int>> GetTargetTiles();
        void OnGridChanged();
        void RemoveAgent(AgentBehaviour* a);
        template <typename T,typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
        T* CreateObjectAtTile(int x, int y)
        {
            std::cout << "Creating object at tile" << std::endl;
            T* go = GameObject::Instantiate<T>({
                {(float)x, (float)y, 0.0},
                {0.7f, 0.7f, 0.7f},
                {0.0, 0.0, 0.0}},
                m_tiles[x][y]->gameObject->Transform
            );

            auto gridObjectBehaviour  = static_cast<GameObject*>(go)->GetComponent<GridObjectBehaviour>();

            m_tiles[x][y]->AddGridObject(gridObjectBehaviour);
            if (gridObjectBehaviour->Type == GridObjectType::Agent)
            {
                auto agent = gridObjectBehaviour->gameObject->GetComponent<AgentBehaviour>();
                if (agent == nullptr)
                {
					std::cout << "Agents should have an agent behaviour!" << std::endl;
                }
				else
				{
                    agent->gridBehaviour = this;
					m_agents.push_back(agent);
				}
            }
            if (gridObjectBehaviour->Type == GridObjectType::Obstacle)
            {
                OnGridChanged();
            }
            return go;
        }

    private:
        std::vector<AgentBehaviour*> m_agents;
        TileBehaviour* m_tiles[11][11];

        void createTile(int x, int y);
};