#pragma once
#include "Exports.h"
#include "Window.h"

class ENGINEDLL_API Renderer
{
private:
	Window * _window;
	void* VertexArrayID;

public:
	bool start(Window * window);
	bool stop();
	Renderer();
	~Renderer();
	void swapBuffer();
	void clearWindow();
	void setClearColor(float r, float g, float b, float a);
	unsigned int GenerateBuffer(float * buffer, int size);
	void DestroyBuffer(unsigned int buffer);
	void DrawBuffer(unsigned int vtxbuffer, int size);
};

