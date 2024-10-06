#include "GridObjectBehaviour.h"

void GridObjectBehaviour::Initialize(TileBehaviour* parentTile, GridBehaviour* gb)
{
	ParentTile = parentTile;
	gridBehaviour = gb;
}
