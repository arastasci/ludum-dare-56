#pragma once
#include "component.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../render/texture.h"
#include "transform.h"

class RenderProperties : public Component {
public:
    RenderProperties() : Component("RenderProperties") {};
    RenderProperties(std::pair<float, float> TextureCoords);

    GLuint VAO, VBO, EBO, VBO_tex;
    static std::vector<float> Vertices;

    std::pair<float, float> GetTextureCoords();
    void SetTextureCoords(std::pair<float, float> coords);

    bool CheckRequiresUpdate();
    bool CheckHasBuffer();

    void MarkAsUpdated();
    void MarkHasBuffer();

private:
    bool m_requiresUpdate = true;
    bool m_hasBuffer = false;
    std::pair<float, float> m_textureCoords = {0, 0};
};

