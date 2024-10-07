#include "Renderer.h"
#include "../base/transform.h"
#include "../base/renderproperties.h"
#include "../../constants.h"
#include <iostream>
class Material;
Renderer::Renderer(){
    auto aspect = SCREEN_WIDTH / SCREEN_HEIGHT;
    

    GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	
    int width, height, nrChannels;
    
	unsigned char* data = stbi_load(TEXTURE_ATLAS_PATH, &width, &height, &nrChannels, 0);

	if (data)
	{
		GLenum format;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else {
        std::cout << "Failed to load texture" << std::endl;
    }

	stbi_image_free(data);
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
    
    float dx = 1.0 / TEXTURE_ATLAS_TILE_WIDTH;
    float dy = 1.0 / TEXTURE_ATLAS_TILE_HEIGHT;

    float topLeftX = info->GetTextureCoords().first * dx;
    float topLeftY = info->GetTextureCoords().second * dy;

    dx *= info->GetTextureSize().first;
    dy *= info->GetTextureSize().second;
    
    std::vector<float> tex_vertices = {
        topLeftX, topLeftY, // 0.0f, 1.0f, // top left
        topLeftX + dx, topLeftY, // 1.0f, 1.0f, // top right
        topLeftX + dx, topLeftY + dy, // 1.0f, 0.0f, // bottom right


        topLeftX + dx, topLeftY + dy, // 1.0f, 0.0f, // bottom right
        topLeftX, topLeftY + dy, // 0.0f, 0.0f, // bottom left
        topLeftX, topLeftY// 0.0f, 1.0f, // top left
    };
    
    if(!info->CheckHasBuffer()){
        glGenBuffers(1, &(info->VBO));
        glGenBuffers(1, &(info->VBO_tex));

        info->MarkHasBuffer();
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, info->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (RenderProperties::Vertices.size()), RenderProperties::Vertices.data(), GL_STATIC_DRAW); 

    glGenVertexArrays(1, &(info->VAO));
    glBindVertexArray(info->VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates
    glBindBuffer(GL_ARRAY_BUFFER, info->VBO_tex);
    glBufferData(GL_ARRAY_BUFFER, tex_vertices.size() * sizeof(float), tex_vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    info->MarkAsUpdated();
}
void Renderer::ChangeShader(Shader* shader, Material* material)
{
    m_currentShader = shader;
    m_currentShader->use();
    m_currentShader->setMat4("projection", glm::ortho(-ORTHO_WIDTH, ORTHO_WIDTH, -ORTHO_HEIGHT, ORTHO_HEIGHT, 0.1f, 100.f));
    m_currentShader->setMat4("view", glm::lookAt(glm::vec3(5.0f, 5.0f, 3.0f), glm::vec3(5.0f, 5.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)));
    m_currentShader->setMat4("model", glm::mat4(1.0f));
    
}
void Renderer::Initialize()
{
    m_shaders["DefaultShader"] = new Shader("res/shader/vshader.glsl", "res/shader/fshader.glsl");
    m_shaders["FillShader"] = new Shader("res/shader/v_fillshader.glsl", "res/shader/f_fillshader.glsl");
}


void Renderer::Render(RenderProperties *info, transform* t){
    if (!info->IsEnabled())
        return;
    if(info->CheckRequiresUpdate()){
        initBuffer(info, t);
    }
    auto shaderName = info->material->shaderName;
    if ( m_shaders[shaderName] != m_currentShader)
    {
        ChangeShader(m_shaders[shaderName], info->material);
    }
    auto& fMap = info-> material->floatMap;
    for (auto it = fMap.begin(); it != fMap.end(); it++)
    {
        m_currentShader->setFloat((*it).first, (*it).second);
    }
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(t->position.x, t->position.y, t->position.z));
    model = glm::rotate(model, glm::radians(t->rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(t->rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(t->rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(t->scale.x, t->scale.y, t->scale.z));

    m_currentShader->setMat4("model", model);

    glBindVertexArray(info->VAO);
    glDrawArrays(GL_TRIANGLES, 0, RenderProperties::Vertices.size());
    glBindVertexArray(0);
};