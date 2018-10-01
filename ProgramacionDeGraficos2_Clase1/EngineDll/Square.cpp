#include "Square.h"

Square::Square(Renderer * renderer) : Entity(renderer)
{
	material = NULL;
	vertexes = NULL;
	vertexColors = NULL;
	vertexBuffer = -1;
	colorBuffer = -1;

	SetVertex(vertexes, 4);
	SetColors(vertexColors, 4);
}

Square::~Square()
{
}

void Square::SetVertex(float * vertex, int cant)
{
	vertex = new float[12]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		1.0f, 1.0f, 0.0f
	};

	vertexBuffer = renderer->GenerateVertexBuffer(vertex, sizeof(float) * cant * 3);
}

void Square::SetColors(float * vertexColor, int cant)
{
	vertexColor = new float[12]{
		1.0f,  0.0f,  0.0f,
		0.0f,  1.0f,  0.0f,
		0.0f,  0.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
	};

	colorBuffer = renderer->GenerateColorBuffer(vertexColor, sizeof(float) * cant * 3);
}

void Square::Draw()
{
	renderer->LoadIdentityMatrix();
	renderer->SetModel(model);

	if (material != NULL)
	{
		material->Bind();
		material->SetMatrixProperty("ModelViewProjectionMatrix", renderer->GetModelViewProjectionMatrix());
	}
	renderer->EnableVertexAttribute(0);
	renderer->EnableVertexAttribute(1);
	renderer->BindBuffer(vertexBuffer,0);
	renderer->BindBuffer(colorBuffer, 1);
	renderer->DrawArrayBuffers(4);
	renderer->DisableVertexAttribute(0);
	renderer->DisableVertexAttribute(1);
}

void Square::SetMaterial(Material * _material)
{
	material = _material;
}