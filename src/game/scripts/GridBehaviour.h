#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/transform.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"


class GridBehaviour : public Behaviour {
    public:
        GridBehaviour() : Behaviour("GridBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();

    private:
        Tile* m_tiles[11][11];

        template <typename T,typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
        T* createObjectAtTile(int x , int y)
        {
            T* go = GameObject::Instantiate<T>( {{(float)x, (float)y, 0.0}, 
                {1.0, 1.0, 1.0}, 
                {0.0, 0.0, 0.0}}
            );
            
            m_tiles[x + 5][y + 5]->GetComponent<TileBehaviour>()->gridObject = go;

            return go;
        }

        void createTile(int x, int y);
};