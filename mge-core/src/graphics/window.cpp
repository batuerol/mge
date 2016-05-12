#include "window.h"

#include <functional>

namespace mge
{
	namespace graphics
	{		
		Window::Window(const char* title, int width, int height) :
			m_pTitle(title), m_Width(width), m_Height(height)
		{
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::Init()
		{
			if (!glfwInit())
			{
				std::cerr << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_pWindow = glfwCreateWindow(m_Width, m_Height, m_pTitle, nullptr, nullptr);

			if (!m_pWindow)
			{
				glfwTerminate();
				std::cerr << "Failed to create GLFW window!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_pWindow);
			glfwSetWindowUserPointer(m_pWindow, this);
			//glfwSetWindowCloseCallback(m_window, callback_windowClose);			
			glfwSetWindowSizeCallback(m_pWindow, callback_windowResize);

			if (glewInit() != GLEW_OK)
			{
				std::cerr << "Failed to initialize GLEW!" << std::endl;
				return false;
			}

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

			return true;
		}

		void Window::Update()
		{
			glfwSwapBuffers(m_pWindow);

			glfwPollEvents();
		}

		void Window::Clear(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_pWindow) == GL_TRUE;
		}

		void Window::callback_windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void Window::callback_windowClose(GLFWwindow* window)
		{
			glfwTerminate();
		}

		void Window::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window *win = (Window *)glfwGetWindowUserPointer(window);			
			s_Keys[key] = action != GLFW_RELEASE;
		}
	}
}