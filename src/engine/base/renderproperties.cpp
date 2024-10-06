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

RenderProperties::RenderProperties(std::pair<float, float> TextureCoords) : Component("RenderProperties")
{
    this->SetTextureCoords(TextureCoords);
}

bool RenderProperties::CheckRequiresUpdate()
{
    return m_requiresUpdate;
}

std::pair<float, float> RenderProperties::GetTextureCoords()
{
    return m_textureCoords;
}

void RenderProperties::SetTextureCoords(std::pair<float, float> coords)
{
    m_textureCoords = coords;
    m_requiresUpdate = true;
}

void RenderProperties::MarkAsUpdated()
{
    m_requiresUpdate = false;
}

bool RenderProperties::CheckHasBuffer()
{
    return m_hasBuffer;
}

void RenderProperties::MarkHasBuffer()
{
    m_hasBuffer = true;
}