#pragma once

#include <unordered_map>

#include <GL/glew.h>

#include "../../math/math.h"
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
			std::unordered_map<std::string, GLint> m_LocationCache;

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

			void SetUniform1i(const std::string& name, int value);
			void SetUniform1f(const std::string& name, float value);
			void SetUniform2f(const std::string& name, float x, float y);
			void SetUniform3f(const std::string& name, float x, float y, float z);
			void SetUniform3f(const std::string& name, const math::vec3& value);
			void SetUniform4f(const std::string& name, const math::vec4& value);
			void SetUniformMat4f(const std::string& name, const math::mat4& value);

		private:
			GLint GetUniformLocation(const std::string& name);
			// TODO(batuhan): Should Load() be static?
			GLuint Load();
			static GLuint CreateShader(const std::string& shaderSource, GLenum shaderType);
			// TODO(batuhan): This is temporary.
			static bool CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
		};
	}
}