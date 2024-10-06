#include <iostream>
#include "TileBehaviour.h"
#include "../prefab/Tile.h"
#include "../../engine/base/gameobject.h"
#include "../../engine/input/input.h"
#include "../prefab/Tile.h"
#include <tuple>
 
std::vector<std::pair<float, float>> TileBehaviour::textureCoords =  {
        {0, 4},
        {1, 4},
};

void TileBehaviour::Start() {
    RenderProperties* rp = this->gameObject->GetComponent<RenderProperties>();
    
    // Pick texture coord
    int option = rand() % this->textureCoords.size();
    
    m_selectedTextureCoord = this->textureCoords[option];
    rp->SetTextureCoords(m_selectedTextureCoord);
};

void TileBehaviour::Update() {
    // std::cout << "TileBehaviour Update" << std::endl;
    RenderProperties* rp = this->gameObject->GetComponent<RenderProperties>();
    
    if(m_hovering){
        if(MouseInput::getInstance().IsButtonRepeated(0)){
            rp->SetTextureCoords({10, 6});
        } else {
            rp->SetTextureCoords({0, 11});
        }
    }
    else
        rp->SetTextureCoords(m_selectedTextureCoord);

    m_hovering = false;
};

void TileBehaviour::OnRaycastHit() {
    m_hovering = true;
};