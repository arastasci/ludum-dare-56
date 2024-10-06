#pragma once
#include "../../engine/base/behaviour.h"
#include <vector>
class GridObjectBehaviour;
class TileBehaviour : public Behaviour
{
public:
    TileBehaviour() : Behaviour("TileBehaviour") {};
    void Start();
    void Update();
    void OnRaycastHit();

    std::vector<GridObjectBehaviour*> gridObjects;
private:
    static std::vector<std::pair<float, float>> textureCoords;
    std::pair<float, float> m_selectedTextureCoord;

    bool m_hovering = false;
};
