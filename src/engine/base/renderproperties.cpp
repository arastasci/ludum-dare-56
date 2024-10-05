#include "renderproperties.h"

// Quad vertices
std::vector<float> RenderProperties::Vertices = {
    -0.5f, 0.5f, 0.0f, // top left point
    0.5f, 0.5f, 0.0f, // top right point
    0.5f, -0.5f, 0.0f, // bottom right point
    0.5f, -0.5f, 0.0f, // bottom right point
    -0.5f, -0.5f, 0.0f, // bottom left point
    -0.5f, 0.5f, 0.0f, // top left point
};