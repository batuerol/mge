#pragma once

#include <vector>
#include <GL\glew.h>

#include "VertexBuffer.h"

namespace mge
{
	namespace graphics
	{
		namespace API
		{
			class VertexArray
			{
			private:
				GLuint m_ArrayID;
				std::vector<VertexBuffer*> m_Buffers;

			public:
				VertexArray();
				~VertexArray();

				void PushBuffer(VertexBuffer* buffer, GLuint index);
				void Bind();
				void Unbind();

			private:
				VertexArray(const VertexArray& rhs) = delete;
				VertexArray(VertexArray&& rhs) = delete;

			};
		}
	}
}
