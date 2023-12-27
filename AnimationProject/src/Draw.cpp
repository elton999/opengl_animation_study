#include "Draw.h"
#include "glad.h"
#include <iostream>

static GLenum DrawModeToGLEnum(DrawMode input)
{
	switch (input)
	{
	case DrawMode::Points:
		return GL_POINTS;
		break;
	case DrawMode::LineStrip:
		return GL_LINE_STRIP;
		break;
	case DrawMode::LineLoop:
		return GL_LINE_LOOP;
		break;
	case DrawMode::Lines:
		return GL_LINES;
		break;
	case DrawMode::Triangles:
		return GL_TRIANGLES;
		break;
	case DrawMode::TiangleStrip:
		return GL_TRIANGLE_STRIP;
		break;
	case DrawMode::TriangleFan:
		return GL_TRIANGLE_FAN;
		break;
	}

	std::cout << "DrawModeToGLEnum unreachable code hit\n";
	return 0;
}

void Draw(unsigned int vertexCount, DrawMode mode)
{
	glDrawArrays(DrawModeToGLEnum(mode), 0, vertexCount);
}

void Draw(unsigned int vertexCount, DrawMode mode, unsigned int numInstances)
{
	glDrawArraysInstanced(DrawModeToGLEnum(mode), 0, vertexCount, numInstances);
}

void Draw(IndexBuffer& inIndexBuffer, DrawMode mode)
{
	unsigned int handle = inIndexBuffer.GetHandle();
	unsigned int numIndicies = inIndexBuffer.Count();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle);
	glDrawElements(DrawModeToGLEnum(mode), numIndicies, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void DrawInstanced(IndexBuffer& inIndexBuffer, DrawMode mode, unsigned int instanceCount)
{
	unsigned int handle = inIndexBuffer.GetHandle();
	unsigned int numIndicies = inIndexBuffer.Count();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle);
	glDrawElementsInstanced(DrawModeToGLEnum(mode), numIndicies, GL_UNSIGNED_INT, 0, instanceCount);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}