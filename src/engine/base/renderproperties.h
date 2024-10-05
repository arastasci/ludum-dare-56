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

    bool HasBuffer = false;
    GLuint VAO, VBO, EBO, VBO_tex;
    Texture Texture;
    std::vector<float> TexCoords;
    static std::vector<float> Vertices;
};

