#include "Renderer.h"
#include "../base/transform.h"
#include "../base/renderproperties.h"

Renderer::Renderer(){
    m_shader = new Shader("src/engine/render/shader/vshader.glsl", "src/engine/render/shader/fshader.glsl");
    m_shader->use();
    m_shader->setMat4("projection", glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f));
    m_shader->setMat4("view", glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)));
    m_shader->setMat4("model", glm::mat4(1.0f));
};

Renderer* Renderer::instance = nullptr;

Renderer* Renderer::GetInstance()
{
    if(instance == nullptr){
        instance = new Renderer();
    }
    
    return instance;
}

void Renderer::initBuffer(RenderProperties *info, transform* t){        
    glGenBuffers(1, &(info->VBO));
    glBindBuffer(GL_ARRAY_BUFFER, info->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (RenderProperties::Vertices.size()), RenderProperties::Vertices.data(), GL_STATIC_DRAW); 

    glGenVertexArrays(1, &(info->VAO));
    glBindVertexArray(info->VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates
    //glGenBuffers(1, &(info->VBO_tex));
    //glBindBuffer(GL_ARRAY_BUFFER, info->VBO_tex);
    //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(1);

    info->HasBuffer = true;
};

void Renderer::Render(RenderProperties *info, transform* t){
    if(!info->HasBuffer)
        initBuffer(info, t);
    
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(t->position.x, t->position.y, t->position.z));
    model = glm::rotate(model, glm::radians(t->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(t->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(t->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(t->scale.x, t->scale.y, t->scale.z));

    m_shader->setMat4("model", model);

    glBindVertexArray(info->VAO);
    glDrawArrays(GL_TRIANGLES, 0, RenderProperties::Vertices.size());
    glBindVertexArray(0);
};