#include "src\graphics\window.h"

int main()
{
	using namespace mge::graphics;
	Window window("Hello!", 800, 600);
	window.Init();	

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed())
	{		
		window.Clear(0.2f, 0.3f, 0.8f, 1.0f);
		
		if (window.IsMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			std::cout << "A Key is pressed." << std::endl;
		}

		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, +0.5f);
		glVertex2f(+0.5f, +0.5f);
		glVertex2f(+0.5f, -0.5f);
		glEnd();

		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);

		window.Update();
	}
	
	return 0;
}