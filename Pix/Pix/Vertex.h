#pragma once

#include "MathHelper.h"
#include "XEngine.h"

struct Vertex
{
	Vector3 pos;
	X::Color color;

};

inline static Vector3 LerpPosition(const Vector3& a, const Vector3& b, float t)
{
	Vector3 pos;
	pos.x = MatheHelper::Lerp(a.x, b.x,t);
	pos.y = MatheHelper::Lerp(a.y, b.y, t);
	pos.z = MatheHelper::Lerp(a.z, b.z, t);
	return pos;

}

inline static X::Color LerpColor(const X::Color& a, const X::Color& b, float t)
{
	X::Color color;
	color .r = MatheHelper::Lerp(a.r, b.r, t);
	color.g = MatheHelper::Lerp(a.g, b.g, t);
	color.b = MatheHelper::Lerp(a.b, b.b, t);
	color.a = MatheHelper::Lerp(a.a, b.a, t);

	return color;

}

//
inline static Vertex LerpVertex(const Vertex& a, const Vertex& b, float t)
{
	Vertex vertex;
	vertex.pos = LerpPosition(a.pos, b.pos, t);
	vertex.color = LerpColor(a.color, b.color, t);


	return vertex;

}

