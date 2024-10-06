#pragma once
#include "../../engine/base/behaviour.h"

class TileBehaviour : public Behaviour
{
public:
    TileBehaviour() : Behaviour("TileBehaviour") {};
    void Start();
private:
    static std::vector<std::pair<float, float>> TextureCoords;
};
