#include "Shader.h"

// TODO(batuhan): Obviously this needs to change.
mge::shader::Shader::Shader(const char * vertexFile, const char * fragmentFile)
{
	m_pShaders = new GLuint[ShaderType::NUM_SHADERS];
}

mge::shader::Shader::~Shader()
{
	for (int i = 0; i < ShaderType::NUM_SHADERS; ++i)
	{
		glDetachShader(m_ShaderProgram, m_pShaders[i]);
		glDeleteShader(m_pShaders[i]);
	}

	glDeleteProgram(m_ShaderProgram);
}

void mge::shader::Shader::Bind()
{
	glUseProgram(m_ShaderProgram);
}

void mge::shader::Shader::Unbind()
{
	glUseProgram(0);
}

GLuint mge::shader::Shader::Load()
{
	m_ShaderProgram = glCreateProgram();	

	std::string vertSource = mge::utils::ReadFile(m_pVertexFile).c_str();
	std::string fragSource = mge::utils::ReadFile(m_pFragmentFile);

	GLuint vertShader = Shader::CreateShader(vertSource, GL_VERTEX_SHADER);
	GLuint fragmentShader = Shader::CreateShader(fragSource, GL_FRAGMENT_SHADER);
	
	// TODO(batuhan): Status check for both.
	glLinkProgram(m_ShaderProgram);
	glValidateProgram(m_ShaderProgram);	

	return m_ShaderProgram;
}

GLuint mge::shader::Shader::CreateShader(const std::string & shaderSource, GLenum shaderType)
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

	return shader;
}
