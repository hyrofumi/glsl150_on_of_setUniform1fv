#version 330

uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

in vec4 position;
in vec2 texcoord;
in vec4 normal;
in vec4 color;


void main()
{
  gl_Position = modelViewProjectionMatrix * position;
}
