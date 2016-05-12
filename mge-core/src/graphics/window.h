#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <iostream>

// TODO(batuhan): Change input handling.
// TODO(batuhan): GLFW is temporary. Get rid of GLFW completely.

namespace mge
{
	namespace graphics
	{
#define MAX_KEYS	1024
#define MAX_BUTTONS 32

		class Window
		{
		private:
			const char *m_pTitle;
			int m_Width, m_Height;
			bool m_Closed;
			GLFWwindow *m_pWindow;

			static bool s_Keys[MAX_KEYS];
			static bool s_MouseButtons[MAX_BUTTONS];
			static double s_mouseX, s_mouseY;

		public:
			Window(const char* title, int width, int height);
			~Window();

			bool Init();
			void Update();
			void Clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f);
			bool Closed() const;

			inline int GetWidth() const
			{
				return m_Width;
			}

			inline int GetHeight() const
			{
				return m_Height;
			}

		private:
			static void callback_windowResize(GLFWwindow* window, int width, int height);
			static void callback_windowClose(GLFWwindow* window);
			static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
		};
	}
}