#include "Triangle.h"

Triangle::Triangle(Renderer * renderer) : Entity(renderer)
{
	material = NULL;
	vertex = NULL;
	vertexColors = NULL;
	vertexBuffer = -1;

	SetVertexBuffer(vertex, 3);
}

Triangle::~Triangle()
{
}

void Triangle::SetVertexBuffer(float * vertex, int cant)
{
	vertex = new float[9]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	vertexBuffer = renderer->GenerateVertexBuffer(vertex, sizeof(float) * cant * 3);
}


void Triangle::Draw()
{
	renderer->LoadIdentityMatrix();
	renderer->SetModel(model);

	if (material != NULL)
	{
		material->Bind();
		material->SetMatrixProperty("ModelViewProjectionMatrix", renderer->GetModelViewProjectionMatrix());
	}
	renderer->EnableVertexAttribute(0);
	renderer->BindBuffer(vertexBuffer, 0);
	renderer->DrawArrayBuffers(3);
	renderer->DisableVertexAttribute(0);
}

void Triangle::SetMaterial(Material * _material)
{
	material = _material;
}