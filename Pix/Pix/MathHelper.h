#pragma once

#include "Vector2.h"
#include "Vector3.h"

class MatheHelper
{
public:
	static bool checkEqual(float a, float b);


	static float MagnitudeSquared(Vector2& v);
	static float MagnitudeSquared(Vector3& v);
	static float Magnitude(Vector2& v);
	static float Magnitude(Vector3& v);
	static Vector2 Normalize(Vector2& v);
	static Vector3 Normalize(Vector3& v);
	static float Dot(Vector2 & a, Vector2& b);
	static float Dot(Vector3 & a, Vector3& b);
	static Vector3 Cross(Vector3 &a, Vector3& b);
	static float Lerp(float a, float b, float t);

};