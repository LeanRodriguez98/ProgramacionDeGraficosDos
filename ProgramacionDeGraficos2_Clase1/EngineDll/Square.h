#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Square : public Entity
{
private:
	float * vertexes;
	float * vertexColors;
	unsigned int vertexBuffer;
	unsigned int colorBuffer;
	Material * material;
	void SetVertex(float * vertex, int cant);
	void SetColors(float * vertexColor, int cant);
public:
	Square(Renderer * renderer);
	~Square();
	void Draw() override;
	void SetMaterial(Material * _material);
};