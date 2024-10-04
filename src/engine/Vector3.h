#pragma once
#include <cmath>

struct Vector3 {
	float x, y, z;

	Vector3() : x(0), y(0), z(0) {}

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	Vector3 operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	Vector3 operator-(const Vector3& other) const {
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	Vector3 operator*(float scalar) const {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3 operator/(float scalar) const {
		return Vector3(x / scalar, y / scalar, z / scalar);
	}

	Vector3& operator+=(const Vector3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3& operator-=(const Vector3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3& operator*=(float scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vector3& operator/=(float scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	bool operator==(const Vector3& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	bool operator!=(const Vector3& other) const {
		return x != other.x || y != other.y || z != other.z;
	}

	Vector3 operator-() const {
		return Vector3(-x, -y, -z);
	}

	float magnitude() const {
		return sqrt(x * x + y * y + z * z);
	}

	Vector3 normalized() const {
		float mag = magnitude();
		if (mag == 0) return Vector3(0, 0, 0);
		return *this / mag;
	}

	float dot(const Vector3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3 cross(const Vector3& other) const {
		return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	static Vector3 lerp(const Vector3& a, const Vector3& b, float t) {
		return a + (b - a) * t;
	}

	static Vector3 slerp(const Vector3& a, const Vector3& b, float t) {
		float dot = a.normalized().dot(b.normalized());
		dot = fmaxf(fminf(dot, 1), -1);
		float theta = acos(dot) * t;
		Vector3 relative = (b - a * dot).normalized();
		return a * cos(theta) + relative * sin(theta);
	}

	static Vector3 up() {
		return Vector3(0, 1, 0);
	}

	static Vector3 down() {
		return Vector3(0, -1, 0);
	}

	static Vector3 left() {
		return Vector3(-1, 0, 0);
	}

	static Vector3 right() {
		return Vector3(1, 0, 0);
	}

	static Vector3 forward() {
		return Vector3(0, 0, 1);
	}

	static Vector3 back() {
		return Vector3(0, 0, -1);
	}

	static Vector3 zero() {
		return Vector3(0, 0, 0);
	}

	static Vector3 one() {
		return Vector3(1, 1, 1);
	}
};