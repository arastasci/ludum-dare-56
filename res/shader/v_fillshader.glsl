#version 330 core

layout(location = 0) in vec3 position;
layout (location= 1) in vec2 texCoords;

out vec2 TexCoords;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
    TexCoords = vec2(texCoords.x, texCoords.y);
}