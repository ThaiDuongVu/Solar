#version 330 core
out vec4 color;

uniform float red = 1.0f;
uniform float green = 1.0f;
uniform float blue = 1.0f;
uniform float alpha = 1.0f;

void main()
{
	color = vec4(red, green, blue, alpha);
}