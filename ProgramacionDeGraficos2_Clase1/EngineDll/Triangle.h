#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINEDLL_API Triangle:public Entity
{
private:
	float * vertex;
	Material * material;
	bool shouldDispause;
	float bufferid;
public:
	Triangle(Renderer * renderer);
	~Triangle();
	void SetVertices(float vertex[], int cant);
	void Draw() override;
	void SetMaterial(Material* _material);
};

