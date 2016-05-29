#include "Shader.h"

#include <iostream>

namespace mge
{
	namespace graphics
	{
		// TODO(batuhan): Obviously this needs to change.
		Shader::Shader(const char * vertexFile, const char * fragmentFile) :
			m_pVertexFile(vertexFile), m_pFragmentFile(fragmentFile)
		{
			m_pShaders = new GLuint[ShaderType::NUM_SHADERS];
			Load();
		}

		Shader::~Shader()
		{
			for (int i = 0; i < ShaderType::NUM_SHADERS; ++i)
			{
				glDetachShader(m_ShaderProgram, m_pShaders[i]);
				glDeleteShader(m_pShaders[i]);
			}

			glDeleteProgram(m_ShaderProgram);
		}

		void Shader::Enable()
		{
			glUseProgram(m_ShaderProgram);
		}

		void Shader::Disable()
		{
			glUseProgram(0);
		}

		void Shader::SetUniform1i(const std::string & name, int value)
		{
			GLint location = GetUniformLocation(name);
			glUniform1i(location, value);
		}

		void Shader::SetUniform1f(const std::string & name, float value)
		{
			GLint location = GetUniformLocation(name);
			glUniform1f(location, value);
		}

		void Shader::SetUniform2f(const std::string & name, float x, float y)
		{
			GLint location = GetUniformLocation(name);
			glUniform2f(location, x, y);
		}

		void Shader::SetUniform3f(const std::string & name, float x, float y, float z)
		{
			GLint location = GetUniformLocation(name);
			glUniform3f(location, x, y, z);
		}

		void Shader::SetUniform3f(const std::string & name, const math::vec3 & value)
		{
			GLint location = GetUniformLocation(name);
			glUniform3f(location, value.x, value.y, value.z);
		}

		void Shader::SetUniform4f(const std::string & name, const math::vec4 & value)
		{
			GLint location = GetUniformLocation(name);
			glUniform4f(location, value.x, value.y, value.z, value.w);
		}

		void Shader::SetUniformMat4f(const std::string & name, const math::mat4 & value)
		{
			GLint location = GetUniformLocation(name);
			glUniformMatrix4fv(location, 1, GL_FALSE, value.elements);
		}

		GLint Shader::GetUniformLocation(const std::string & name)
		{
			if (m_LocationCache.find(name) != m_LocationCache.end())
			{
				return m_LocationCache[name];
			}

			GLint result = glGetUniformLocation(m_ShaderProgram, name.c_str());
			if (result != -1)
			{
				m_LocationCache[name] = result;
			}
			else
			{
				// TODO(batuhan): Uniform could not found.
			}

			return result;
		}

		GLuint Shader::Load()
		{
			m_ShaderProgram = glCreateProgram();

			std::string vertSource = mge::utils::ReadFile(m_pVertexFile);
			std::string fragSource = mge::utils::ReadFile(m_pFragmentFile);

			GLuint vertShader = Shader::CreateShader(vertSource, GL_VERTEX_SHADER);
			GLuint fragmentShader = Shader::CreateShader(fragSource, GL_FRAGMENT_SHADER);

			glAttachShader(m_ShaderProgram, vertShader);
			glAttachShader(m_ShaderProgram, fragmentShader);

			// TODO(batuhan): Status check for both.
			glLinkProgram(m_ShaderProgram);
			CheckShaderError(m_ShaderProgram, GL_LINK_STATUS, true, "Linking program failed");
			glValidateProgram(m_ShaderProgram);
			CheckShaderError(m_ShaderProgram, GL_VALIDATE_STATUS, true, "Validation failed");

			return m_ShaderProgram;
		}

		GLuint Shader::CreateShader(const std::string & shaderSource, GLenum shaderType)
		{
			GLuint shader = glCreateShader(shaderType);
			if (shader == 0)
			{
				// TODO(batuhan): Shader creation failed. Diagnostic
				return -1;
			}
			int length = shaderSource.length();
			const GLchar* source = shaderSource.c_str();
			glShaderSource(shader, 1, &source, &length);
			glCompileShader(shader);
			// TODO(batuhan): Check shader compile status
			CheckShaderError(shader, GL_COMPILE_STATUS, false, "Shader compile error");

			return shader;
		}

		// TODO(batuhan): This is temporary.
		bool Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage)
		{
			GLint success = GL_FALSE;
			GLchar error[1024] = { 0 };

			if (isProgram)
			{
				glGetProgramiv(shader, flag, &success);
			}
			else
			{
				glGetShaderiv(shader, flag, &success);
			}

			if (success == GL_FALSE)
			{
				if (isProgram)
				{
					glGetProgramInfoLog(shader, sizeof(error), NULL, error);
				}
				else
				{
					glGetShaderInfoLog(shader, sizeof(error), NULL, error);
				}

				std::cerr << errorMessage << ": '" << error << "'" << std::endl;
			}

			return success == GL_TRUE;
		}
	}
}