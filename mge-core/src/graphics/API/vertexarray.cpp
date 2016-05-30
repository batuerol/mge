#include "vertexarray.h"

namespace mge
{
	namespace graphics
	{
		namespace API
		{
			VertexArray::VertexArray()
			{
				// TODO(batuhan): Multiple vertex arrays?
				// Create static method maybe?
				glGenVertexArrays(1, &m_ArrayID);
			}

			VertexArray::~VertexArray()
			{
				for (int i = 0; i < m_Buffers.size(); ++i)
				{
					delete m_Buffers[i];
				}
			}

			void VertexArray::PushBuffer(VertexBuffer* buffer, GLuint index)
			{
				Bind();
				buffer->Bind();

				glEnableVertexAttribArray(index);
				glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);				

				buffer->Unbind();
				Unbind();
				
				m_Buffers.push_back(buffer);
			}

			void VertexArray::Bind()
			{
				glBindVertexArray(m_ArrayID);
			}

			void VertexArray::Unbind()
			{
				glBindVertexArray(0);
			}
		}
	}
}
