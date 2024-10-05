#pragma once
#include "../base/transform.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "texture.h"
#include "../base/transform.h"
#include "shader.h"

struct renderinfo {
    bool hasBuffer = false;
    GLuint VAO, VBO, EBO, VBO_tex;
    Texture texture;
    std::vector<float> texCoords;
    std::vector<float> vertices;
};

class Renderer
{
protected:
    Renderer();
    static Renderer* instance;
    Shader* m_shader;

    void initBuffer(renderinfo &info, transform& t);
public:
    Renderer(Renderer &other) = delete;
    void operator=(const Renderer &) = delete;
    
    static Renderer *GetInstance();

    void Render(renderinfo &info, transform& t);
};
