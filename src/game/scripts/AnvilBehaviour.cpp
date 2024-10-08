#pragma once
#include "../../engine/base/behaviour.h"
#include "AnvilBehaviour.h"
#include "../../engine/easing.h"
#include "../../engine/timer.h"
#include <iostream>
#include "Enemy.h"

double AnvilBehaviour::animationDuration = .2f;

void AnvilBehaviour::Start() {
    std::cout << "AnvilBehaviour Start" << std::endl;
    
    GameManagerBehaviour::GetInstance()->OnAnvilUsed();
    m_createdAt = Timer::getInstance().getElapsedTime();
    m_landsTo = this->gameObject->Transform->position;

    auto tileBehaviour = gameObject->Transform->GetParent()->gameObject->GetComponent<TileBehaviour>();

    auto agents = tileBehaviour->GetObjectsByType(GridObjectType::Agent);
    

    for(auto agent : agents) {
        if (agent->gameObject->GetComponent<Enemy>() != nullptr)
        {
            tileBehaviour->RemoveGridObject(agent);
            agent->gameObject->Destroy();
        }
    }
}

void AnvilBehaviour::Update() {
    double dt = Timer::getInstance().getElapsedTime() - m_createdAt;
    
    if(dt > animationDuration) {
        return;
    }

    float landY = m_landsTo.y;
    this->gameObject->Transform->position.y = 1 + landY - easeOutBounce(dt/animationDuration);
}