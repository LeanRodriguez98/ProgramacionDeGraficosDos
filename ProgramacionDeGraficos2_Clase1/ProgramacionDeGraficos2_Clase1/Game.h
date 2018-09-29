#pragma once
#include "GameBase.h"
#include "Renderer.h"
#include <Triangle.h>
class Game :public GameBase
{
private:
	Triangle * triangle_1;
	Material * material1;
protected:
	bool onStart() override;
	bool onStop() override;
	bool onUpdate() override;
	bool OnDraw() override;

public:
	int i;
	Game();
	~Game();
};

