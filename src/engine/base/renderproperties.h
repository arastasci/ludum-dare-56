#pragma once
#include "component.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../render/texture.h"
#include "transform.h"
#include "../render/Material.h"

class RenderProperties : public Component {
public:
    RenderProperties(std::pair<float, float> TextureCoords);
    RenderProperties(std::pair<float, float> TextureCoords, std::pair<int, int> TextureSize);

    RenderProperties(std::pair<float, float> TextureCoords, Material* m);

    GLuint VAO, VBO, EBO, VBO_tex;
    static std::vector<float> Vertices;

    std::pair<float, float> GetTextureCoords();
    std::pair<int, int> GetTextureSize();
    void SetTextureCoords(std::pair<float, float> coords);
    void SetTextureSize(std::pair<int, int> size);

    bool CheckRequiresUpdate();
    bool CheckHasBuffer();

    void MarkAsUpdated();
    void MarkHasBuffer();
    void SetIsEnabled(bool value);
    bool IsEnabled();
    Material* material;
private:
    
    bool m_isEnabled = true;
    bool m_requiresUpdate = true;
    bool m_hasBuffer = false;
    
    std::pair<float, float> m_textureCoords = {0, 0};
    std::pair<int, int> m_textureSize = {1, 1};
};

