#pragma once
#include "../../engine/base/behaviour.h"
#include <vector>
class GridObjectBehaviour;
class GridBehaviour;
class TileBehaviour : public Behaviour
{
public:
    TileBehaviour() : Behaviour("TileBehaviour") {};
    void Start();
    void Update();
    void OnRaycastHit();

    std::vector<GridObjectBehaviour*> gridObjects;
    
    void Initialize(int x, int y, GridBehaviour* gridBehaviour);
    void RemoveGridObject(GridObjectBehaviour* gridObject);
    void AddGridObject(GridObjectBehaviour* gridObject);
    TileBehaviour* GetNeighbour(int x, int y);
    GridBehaviour* gridBehaviour;
    
    int x, y;
private:
    static std::vector<std::pair<float, float>> textureCoords;
    std::pair<float, float> m_selectedTextureCoord;

    bool m_hovering = false;
};
