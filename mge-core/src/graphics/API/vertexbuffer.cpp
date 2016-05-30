#include "vertexbuffer.h"

namespace mge
{
	namespace graphics
	{
		namespace API
		{
			VertexBuffer::VertexBuffer(GLfloat * data, GLsizei count, GLuint componentCount) :
				m_ComponentCount(componentCount)
			{
				glGenBuffers(1, &m_BufferID);
				glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
				glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}

			void VertexBuffer::Bind()
			{
				glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
			}

			void VertexBuffer::Unbind()
			{
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}
		}
	}
}
