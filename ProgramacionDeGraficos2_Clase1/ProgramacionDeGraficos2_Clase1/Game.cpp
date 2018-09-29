#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}


bool Game::onStart()
{
	i = 0;
	material1 = new Material();
	unsigned int ProgramID = material1->LoadShaders("vertexshader.txt", "fragmentshader.txt");
	triangle_1 = new Triangle(renderer);
	triangle_1->SetMaterial(material1);
	return true;
}

bool Game::onStop()
{
	return false;
}

bool Game::onUpdate()
{
	i++;
	if (i < 100000000)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Game::OnDraw() 
{
	triangle_1->Draw();
	return true;
}

