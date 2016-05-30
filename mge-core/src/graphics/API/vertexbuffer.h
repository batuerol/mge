#pragma once

#include <GL\glew.h>

namespace mge
{
	namespace graphics
	{
		namespace API
		{
			class VertexBuffer
			{
			private:
				GLuint m_BufferID;
				GLuint m_ComponentCount;

			public:
				VertexBuffer(GLfloat* data, GLsizei count, GLuint componentCount);

				void Bind();
				void Unbind();

				inline GLuint GetComponentCount() const
				{
					return m_ComponentCount;
				}

			private:
				VertexBuffer(const VertexBuffer& rhs) = delete;
				VertexBuffer(VertexBuffer&& rhs) = delete;
			};
		}
	}
}