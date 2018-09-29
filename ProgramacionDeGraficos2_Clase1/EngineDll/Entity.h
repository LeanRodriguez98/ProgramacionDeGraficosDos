#pragma once
#include "Renderer.h"
class ENGINEDLL_API Entity
{
protected:
	Renderer * renderer;
public:
	virtual void Draw() = 0;
	Entity(Renderer * renderer);
	~Entity();
};

