#pragma once

#include <GL/glew.h>

#include "../../utils/fileutils.h"

namespace mge
{
	namespace graphics
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

			void Enable();
			void Disable();

		private:
			// TODO(batuhan): Should Load() be static?
			GLuint Load();
			static GLuint CreateShader(const std::string& shaderSource, GLenum shaderType);
			// TODO(batuhan): This is temporary.
			static bool CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
		};
	}
}