#pragma once
#include "../../engine/base/behaviour.h"
#include "AnvilBehaviour.h"
#include "../../engine/easing.h"
#include "../../engine/timer.h"

double AnvilBehaviour::animationDuration = 1.0;

void AnvilBehaviour::Start() {
    m_createdAt = Timer::getInstance().getElapsedTime();
    m_landsTo = this->gameObject->Transform->position;
}

void AnvilBehaviour::Update() {
    double dt = Timer::getInstance().getElapsedTime() - m_createdAt;
    
    if(dt > animationDuration) {
        return;
    }

    float landY = m_landsTo.y;
    this->gameObject->Transform->position.y = 1 + landY - easeOutBounce(dt/animationDuration);
}