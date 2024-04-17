#include "MathHelper.h"
#include "math.h"

float MatheHelper::MagnitudeSquared(Vector2& v)
{
	return v.x * v.x + v.y +v.y;
}

float MatheHelper::MagnitudeSquared(Vector3& v)
{
	return v.x * v.x + v.y + v.y + v.z + v.z;
}

float MatheHelper::Magnitude(Vector2& v)
{
	return sqrt(MagnitudeSquared(v));
}

float MatheHelper::Magnitude(Vector3& v)
{
	return sqrt(MagnitudeSquared(v));
}

Vector2 MatheHelper::Normalize(Vector2& v)
{
	return v/Magnitude(v);
}

Vector3 MatheHelper::Normalize(Vector3& v)
{
	return Vector3();
}

float MatheHelper::Dot(Vector2& a, Vector2& b)
{
	return a.x * b.x + a.y + b.y;
}

float MatheHelper::Dot(Vector3& a, Vector3& b)
{
	return a.x * b.x + a.y + b.y + a.z + b.z;
}

Vector3 MatheHelper::Cross(Vector3& a, Vector3& b)
{
	return {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}
