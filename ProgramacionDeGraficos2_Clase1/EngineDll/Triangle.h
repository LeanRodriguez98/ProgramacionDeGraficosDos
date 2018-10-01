#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Triangle:public Entity
{
private:
	float * vertex;
	float * vertexColors;
	unsigned int vertexBuffer;
	unsigned int colorBuffer;
	Material * material;
	void SetVertexBuffer(float * vertex, int cant);
public:
	Triangle(Renderer * renderer);
	~Triangle();
	void Draw() override;
	void SetMaterial(Material * _material);
};

