#include "Triangle.h"



Triangle::Triangle(Renderer	* renderer):Entity(renderer)
{
	shouldDispause = false;
	material = NULL;
	vertex = NULL;
	bufferid = -1;

	SetVertices(vertex, 3);
}


Triangle::~Triangle()
{
}

void Triangle::SetVertices(float vertex[], int cant)
{
	vertex = new float[9]
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	bufferid = renderer->GenerateBuffer(vertex, sizeof(float) * cant * 3);
}


void Triangle::Draw() 
{
	if (material != NULL)
	{
		material->Bind();
	}
	this->renderer->DrawBuffer(bufferid, 3);

}

void Triangle::SetMaterial(Material * _material)
{
	material = _material;
}