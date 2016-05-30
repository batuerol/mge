#pragma once

#include <GL\glew.h>

namespace mge
{
	namespace graphics
	{
		namespace API
		{
			class IndexBuffer
			{
			private:
				GLuint m_BufferID;
				GLuint m_Count;

			public:
				IndexBuffer(GLushort *data, GLsizei count);

				void Bind();
				void Unbind();

				inline GLuint GetCount() const
				{
					return m_Count;
				}

			private:
				IndexBuffer(const IndexBuffer& rhs) = delete;
				IndexBuffer(IndexBuffer&& rhs) = delete;
			};
		}
	}
}
