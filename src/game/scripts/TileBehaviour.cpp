#include <iostream>
#include "TileBehaviour.h"
#include "../prefab/Tile.h"
#include "../../engine/base/gameobject.h"
#include "../prefab/Tile.h"
#include <tuple>
 
std::vector<std::pair<float, float>> TileBehaviour::TextureCoords =  {
        {0, 4},
        {1, 4},
};

void TileBehaviour::Start() {
    RenderProperties* rp = dynamic_cast<RenderProperties*>(this->gameObject->GetComponent("RenderProperties"));
    
    // Pick texture coord
    int option = rand() % this->TextureCoords.size();

    rp->TextureCoords = this->TextureCoords[option];
};