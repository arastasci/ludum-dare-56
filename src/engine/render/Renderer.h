#pragma once
#include "../base/transform.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "texture.h"
#include "../base/transform.h"
#include "shader.h"
#include "../base/renderproperties.h"
#include <unordered_map>
class Renderer
{
protected:
    Renderer();
    static Renderer* instance;
    Shader* m_currentShader;
    std::unordered_map<std::string, Shader*> m_shaders;
    void initBuffer(RenderProperties *info, transform* t);

public:
    void ChangeShader(Shader* shader, Material& material);
    void Initialize();
    Renderer(Renderer &other) = delete;
    void operator=(const Renderer &) = delete;
    
    static Renderer *GetInstance();

    void Render(RenderProperties *info, transform* t);
};
