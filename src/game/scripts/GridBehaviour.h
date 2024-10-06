#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/transform.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include "GridObjectBehaviour.h"

class GridBehaviour : public Behaviour {
    public:
        GridBehaviour() : Behaviour("GridBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();

    private:
        Tile* m_tiles[11][11];

        template <typename T,typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
        T* createObjectAtTile(int x, int y)
        {
            T* go = GameObject::Instantiate<T>({
                {(float)x, (float)y, 0.0},
                {0.7f, 0.7f, 0.7f},
                {0.0, 0.0, 0.0} }
            );

            auto gridObjectBehaviour  = static_cast<GameObject*>(go)->GetComponent<GridObjectBehaviour>();
            m_tiles[x + 5][y + 5]->GetComponent<TileBehaviour>()->gridObjects.push_back(gridObjectBehaviour);
            gridObjectBehaviour->Initialize(m_tiles[x + 5][y + 5]);

            return go;
        }

        void createTile(int x, int y);
};