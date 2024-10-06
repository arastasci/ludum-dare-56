#pragma once
#include "../../engine/base/behaviour.h"
#include "../../engine/base/transform.h"
#include "../../engine/base/gameobject.h"


class GridBehaviour : public Behaviour {
    public:
        GridBehaviour() : Behaviour("GridBehaviour") {};
        void Start();
        void Update();
        void OnDestroy();

    private:
        std::vector<GameObject*> m_tiles[11][11];

        template <typename T,typename = std::enable_if_t<std::is_base_of_v<GameObject, T>>>
        T* createObjectAtTile(transform t)
        {
            T* go = GameObject::Instantiate<T>(t);

            // this is so wrong but I need to sleep.
            m_tiles[(int)t.position.x + 5][(int)t.position.y + 5].push_back(go);

            return go;
        }
};