#include "GameBase.h"
#include "TypeDefs.h"
#include <iostream>


GameBase::GameBase()
{
	renderer = new Renderer;
}


GameBase::~GameBase()
{
	delete renderer;
}

bool GameBase::start()
{
	window = new Window(800, 600,  (char*)"window");
	window->start();

	if (!renderer->start(window))
	{
		std::cout << "no se pudo iniciar el renderer" << std::endl;
		std::cin.get();
		return false;
	}

	renderer->setClearColor(0,1,0,1);

	return onStart();

}

bool GameBase::stop()
{
	onStop();
	if (renderer->stop())
	{
		std::cout << "no se pudo detener el renderer" << std::endl;
		std::cin.get();
		return false;
	}
	window->stop();
	return true;
}

void GameBase::loop() 
{
	gameover = false;
	while (!gameover && (!window->ShouldClose()))
	{
		gameover = onUpdate();
		renderer->clearWindow();
		OnDraw();
		renderer->swapBuffer();
		window->PollEvents();

	}
}
