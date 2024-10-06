#include "AgentBehaviour.h"
#include "GridBehaviour.h"

void AgentBehaviour::OnGridChanged()
{
}

void AgentBehaviour::OnDestroy()
{
    gridBehaviour->RemoveAgent(this);
};
