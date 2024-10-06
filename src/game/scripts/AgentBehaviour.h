#pragma once
#include "GridObjectBehaviour.h"
#include "PathFinderBehaviour.h"
class AgentBehaviour : public GridObjectBehaviour
{
public:
	AgentBehaviour(const char* name) : GridObjectBehaviour(name, GridObjectType::Agent) {};
    void Start() {};
    void Update() {};
    void OnDestroy() {};
    virtual void OnGridChanged();

    PathFinderBehaviour* pathFinder;

};

