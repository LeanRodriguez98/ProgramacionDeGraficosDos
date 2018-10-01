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
	unsigned int ProgramID = material1->LoadShaders("colorvertexshader.txt", "colorfragmentshader.txt");
	triangle_1 = new Triangle(renderer);
	triangle_1->SetMaterial(material1);
	triangle_1->SetTranslation(4, 0, 0);
	triangle_1->SetScale(3, 3, 0);
	square_1 = new Square(renderer);
	square_1->SetMaterial(material1);
	square_1->SetTranslation(-4, 0, 0);
	square_1->SetScale(3, 3, 0);
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
	square_1->Draw();
	return true;
}

