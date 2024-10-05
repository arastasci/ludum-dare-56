#include "Renderer.h"
#include "../base/transform.h"

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

void Renderer::initBuffer(RenderInfo &info, transform& t){        
    glGenBuffers(1, &(info.VBO));
    glBindBuffer(GL_ARRAY_BUFFER, info.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * info.vertices.size(), info.vertices.data(), GL_STATIC_DRAW); 

    glGenVertexArrays(1, &(info.VAO));
    glBindVertexArray(info.VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &(info.VBO_tex));
    glBindBuffer(GL_ARRAY_BUFFER, info.VBO_tex);
    //glBufferData(GL_ARRAY_BUFFER, data->texCoords.size() * sizeof(float), data->texCoords.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    info.hasBuffer = true;
};

void Renderer::Render(RenderInfo &info, transform& t){
    if(!info.hasBuffer)
        initBuffer(info, t);
    
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(t.position.x, t.position.y, t.position.z));
    model = glm::rotate(model, glm::radians(t.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(t.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(t.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(t.scale.x, t.scale.y, t.scale.z));

    m_shader->setMat4("model", model);

    glBindVertexArray(info.VAO);
    glDrawArrays(GL_TRIANGLES, 0, info.vertices.size());
    glBindVertexArray(0);
};