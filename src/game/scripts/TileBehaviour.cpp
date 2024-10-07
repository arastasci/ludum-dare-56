#include <iostream>
#include "TileBehaviour.h"
#include "../prefab/Tile.h"
#include "../../engine/base/gameobject.h"
#include "../../engine/input/input.h"
#include "../prefab/Tile.h"
#include "../prefab/Anvil.h"
#include "../prefab/Bomb.h"
#include "../prefab/Sledgehammer.h"
#include <tuple>
#include "GridBehaviour.h"
#include "GameManagerBehaviour.h"
std::vector<std::pair<float, float>> TileBehaviour::textureCoords =  {
        {0, 17},
        {1, 17},
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

        if(MouseInput::getInstance().IsButtonPressed(0) && GameManagerBehaviour::GetInstance()->CanUseSledgehammer()){
            transform hammer(*this->gameObject->Transform);
            hammer.position.z = 1.2;
            hammer.rotation = { 0, 0, 45.f };
            hammer.scale = { 0.7, 0.7, 0.7 };

            gridBehaviour->CreateObjectAtTile<Sledgehammer>(x, y, hammer);
        }
        else if (KeyInput::getInstance().IsKeyPressed(GLFW_KEY_F))
        {
            transform bomb(*this->gameObject->Transform);
            bomb.position.z = 1.2;
            bomb.rotation = { 0, 0, 0 };
            bomb.scale = { 0.7, 0.7, 0.7 };

            gridBehaviour->CreateObjectAtTile<Bomb>(x, y, bomb);
        }
        else if (KeyInput::getInstance().IsKeyPressed(GLFW_KEY_R))
        {
            transform anvil(*this->gameObject->Transform);
            anvil.position.z = 1.2;
            anvil.scale = { 0.7, 0.7, 0.7 };

            gridBehaviour->CreateObjectAtTile<Anvil>(x, y, anvil);
        }
        else {
            rp->SetTextureCoords({0, 24});
        }
    }
    else
        rp->SetTextureCoords(m_selectedTextureCoord);

    m_hovering = false;
};

std::vector<GridObjectBehaviour*> TileBehaviour::GetObjectsByType(GridObjectType type)
{
    std::vector<GridObjectBehaviour*> objects;

    //std::cout << "Getting objects by type" << gridObjects.size() << std::endl;

    for (GridObjectBehaviour* obj : gridObjects)
    {
        if (obj->Type == type)
        {
            objects.push_back(obj);
        }
    }

    return objects;
}

void TileBehaviour::OnRaycastHit() {
    m_hovering = true;
}

void TileBehaviour::Initialize(int x, int y, GridBehaviour* gridBehaviour)
{
    this->x = x;
	this->y = y;
	this->gridBehaviour = gridBehaviour;
}

void TileBehaviour::RemoveGridObject(GridObjectBehaviour* gridObject)
{
	gridObjects.erase(std::remove(gridObjects.begin(), gridObjects.end(), gridObject), gridObjects.end());
	gridObject->gameObject->Transform->SetParent(nullptr);
}

void TileBehaviour::AddGridObject(GridObjectBehaviour* gridObject)
{
    gridObjects.push_back(gridObject);
    gridObject->gameObject->Transform->SetParent(this->gameObject->Transform);
}

TileBehaviour* TileBehaviour::GetNeighbour(int x, int y)
{
    auto newX = this->x + x;
    auto newY = this->y + y;
    if (newX < 0 || newY < 0 || newX >= 11 || newY >= 11)
    {
		return nullptr;
	}
    return gridBehaviour->GetTileAt(newX, newY);
}

bool TileBehaviour::IsWalkable()
{
    return (GetObjectsByType(GridObjectType::Obstacle).size() == 0) && (GetObjectsByType(GridObjectType::Trap).size() == 0);
}
