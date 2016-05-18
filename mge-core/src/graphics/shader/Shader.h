#pragma once

#include <GL/glew.h>

#include "../../utils/fileutils.h"

namespace mge
{
	namespace shader
	{
		// TODO(batuhan): Make this base class for directX/GL shaders
		// TODO(batuhan): Single file shaders?		
		class Shader
		{
		protected:
			GLuint m_ShaderProgram;
			GLuint *m_pShaders;
			const char* m_pVertexFile;
			const char *m_pFragmentFile;

			enum ShaderType
			{
				VERTEX_SHADER,
				FRAGMENT_SHADER,
				NUM_SHADERS
			};

		public:
			Shader(const char* vertexFile, const char* fragmentFile);
			virtual ~Shader();

			void Bind();
			void Unbind();

		private:			
			GLuint Load();
			static GLuint CreateShader(const std::string& shaderSource, GLenum shaderType);			
		};
	}
}