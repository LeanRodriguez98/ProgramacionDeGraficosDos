#include "Renderer.h"
#include <GL\glew.h>
#include <GLFW\glfw3.h>
Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

bool Renderer::start(Window * window) 
{
	_window = window;
	glfwMakeContextCurrent((GLFWwindow*)window->GetWindowPtr());
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Falló al inicializar GLEW\n");
		return -1;
	}
	glGenVertexArrays(1, (GLuint*)&VertexArrayID);
	glBindVertexArray((GLuint)VertexArrayID);
	return true;
}

bool Renderer::stop()
{
	return false;
}

void Renderer::swapBuffer() 
{
	glfwSwapBuffers((GLFWwindow*)_window->GetWindowPtr());
}

void Renderer::clearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::setClearColor(float r, float g, float b, float a) 
{
	glClearColor(r,g,b,a);
}

unsigned int Renderer::GenerateBuffer(float * buffer, int size)
{
	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,size, buffer, GL_STATIC_DRAW);
	return vertexBuffer;
}

void Renderer::DestroyBuffer(unsigned int buffer) 
{
	//glDeleteBuffers(buffer);
}

void Renderer::DrawBuffer(unsigned int vertexbuffer, int size)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // atributo 0. No hay razón particular para el 0, pero debe corresponder en el shader.
		3,                  // tamaño
		GL_FLOAT,           // tipo
		GL_FALSE,           // normalizado?
		0,                    // Paso
		(void*)0            // desfase del buffer
	);
	// Dibujar el triángulo !
	glDrawArrays(GL_TRIANGLES, 0, size); // Empezar desde el vértice 0S; 3 vértices en total -> 1 triángulo
	glDisableVertexAttribArray(0);
}

