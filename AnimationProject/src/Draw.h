#ifndef _DRAW_H_
#define _DRAW_H_

#include "IndexBuffer.h"

enum class DrawMode
{
	Points,
	LineStrip,
	LineLoop,
	Lines,
	Triangles,
	TiangleStrip,
	TriangleFan
};

void Draw(IndexBuffer& inIndexBuffer, DrawMode mode);
void Draw(unsigned int vertexCount, DrawMode mode);
void DrawInstanced(IndexBuffer& inIndexBuffer, DrawMode mode, unsigned int instanceCount);
void DrawInstanced(unsigned int vertexCount, DrawMode mode, unsigned int numInstances);

#endif // !_DRAW_H_