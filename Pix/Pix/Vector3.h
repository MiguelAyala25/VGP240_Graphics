#pragma once

struct  Vector3
{


	float x;
	float y;
	float z;

	constexpr Vector3() :x(0), y(0), z(0) {}
	const Vector3(float _s) :x(_s), y(_s), z(_s) {}

	const Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	Vector3 operator+(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	Vector3 operator-(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z - rhs.z); }
	Vector3 operator*(const float s) const { return Vector3(x * s, y * s, z* s); }
	Vector3 operator/(const float s) const { return Vector3(x / s, y / s, z / s); }

	Vector3& operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z;  return *this; }
	Vector3& operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y;  z -= rhs.z; return *this; }

	Vector3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
	Vector3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
};