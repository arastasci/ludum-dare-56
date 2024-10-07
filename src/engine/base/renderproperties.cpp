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
    material = new Material();
    this->SetTextureCoords(TextureCoords);
}


RenderProperties::RenderProperties(std::pair<float, float> TextureCoords, std::pair<int, int> TextureSize) : Component("RenderProperties")
{
    this->SetTextureCoords(TextureCoords);
    this->SetTextureSize(TextureSize);

RenderProperties::RenderProperties(std::pair<float, float> TextureCoords, Material* m) :
   RenderProperties( TextureCoords)
{
    material = m;

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

std::pair<int, int> RenderProperties::GetTextureSize()
{
    return m_textureSize;
}

void RenderProperties::SetTextureSize(std::pair<int, int> size)
{
    m_textureSize = size;
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

void RenderProperties::SetIsEnabled(bool value)
{
    m_isEnabled = value;
}

bool RenderProperties::IsEnabled()
{
    return m_isEnabled;
}
