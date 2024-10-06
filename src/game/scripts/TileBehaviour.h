#pragma once
#include "../../engine/base/behaviour.h"
#include <vector>

enum class GridObjectType;

class GridObjectBehaviour;
class GridBehaviour;
class TileBehaviour : public Behaviour
{
public:
    TileBehaviour() : Behaviour("TileBehaviour") {};
    void Start();
    void Update();
    void OnRaycastHit();
    
    void Initialize(int x, int y, GridBehaviour* gridBehaviour);
    void RemoveGridObject(GridObjectBehaviour* gridObject);
    void AddGridObject(GridObjectBehaviour* gridObject);
    std::vector<GridObjectBehaviour*> GetObjectsByType(GridObjectType type);

    TileBehaviour* GetNeighbour(int x, int y);
    GridBehaviour* gridBehaviour;
    bool IsWalkable();
    
    int x, y;
private: 
    static std::vector<std::pair<float, float>> textureCoords;
    std::pair<float, float> m_selectedTextureCoord;
    std::vector<GridObjectBehaviour*> gridObjects;

    bool m_hovering = false;
};
