#version 330 core

out vec4 FragColor;

in vec2 TexCoords;
uniform sampler2D texture0;
uniform float percentage;
void main()
{
    // FragColor = vec4(0.07f, 0.81f, 0.29f, 1.0);
    vec4 initialColor = texture(texture0, TexCoords);
    vec4 color;
    if(percentage > 1.f)
    {
        color = vec4(0, 1, 0, 1);
    }
    else
    {
        color = vec4(1, 0, 0, 1);
    }
    if(initialColor.a == 1.f)
    {
        FragColor = color * vec4(initialColor.rgb, percentage);
    }
    else
    {
        FragColor = initialColor;
    }

    

}