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
    RenderProperties(std::pair<float, float> TextureCoords) : Component("RenderProperties"), TextureCoords(TextureCoords) {};

    bool HasBuffer = false;
    GLuint VAO, VBO, EBO, VBO_tex;
    std::pair<float, float> TextureCoords = {0, 0};
    static std::vector<float> Vertices;
};

