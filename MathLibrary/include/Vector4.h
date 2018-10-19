////////////////////////////////////////////////////////////
// File: Vector4.h
// Author: Joe Tingle
// Date Created: 26/02/2018
// Brief: Math Library: Basic Vector4 Class with operator overloads
//			Allows for the initalisationa and use of a 4D vector (X,Y,Z,W)
////////////////////////////////////////////////////////////
#ifndef __VECTOR4_H__
#define __VECTOR4_H__
#include "Vector3.h"
class Vector4
{
public:
	~Vector4();

	Vector4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 1.0f;
	}

	Vector4(float X, float Y, float Z, float W)
	{
		x = X;
		y = Y;
		z = Z;
		w = W;
	}
	Vector4(Vector3 &a_oVector, float rotation)
	{
		x = a_oVector.GetX(a_oVector);
		y = a_oVector.GetY(a_oVector);
		z = a_oVector.GetZ(a_oVector);
		w = rotation;
	}

	Vector4 Normalise(Vector4 &a_oVector);
	float Magnitude(Vector4 &a_oVector);
	float DotProduct(Vector4 &a_oVectorA, Vector4 &a_oVectorB);

	const Vector4 operator=(const Vector4 &a_oVector)
	{
		this->x = a_oVector.x;
		this->y = a_oVector.y;
		this->z = a_oVector.z;
		this->w = a_oVector.w;
		return *this;
	}

	const bool operator==(Vector4 const &a_oVector)
	{
		if (x == a_oVector.x && y == a_oVector.y && z == a_oVector.z && w == a_oVector.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const bool operator!=(Vector4 const &a_oVector)
	{
		if (x != a_oVector.x || y != a_oVector.y || z != a_oVector.z || w != a_oVector.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const Vector4 operator+(const Vector4 &a_oVector)
	{
		return Vector4(x + a_oVector.x, y + a_oVector.y, z + a_oVector.z, w + a_oVector.w);
	}

	const Vector4 operator+=(const Vector4 &a_oVector)
	{
		return Vector4(x += a_oVector.x, y += a_oVector.y, z += a_oVector.z, w += a_oVector.w);
	}

	const Vector4 operator-(const Vector4 &a_oVector)
	{
		return Vector4(x - a_oVector.x, y - a_oVector.y, z - a_oVector.z, w - a_oVector.w);
	}

	const Vector4 operator-=(const Vector4 &a_oVector)
	{
		return Vector4(x -= a_oVector.x, y -= a_oVector.y, z -= a_oVector.z, w -= a_oVector.w);
	}

	const Vector4 operator-()
	{
		return Vector4(-x, -y, -z, -w);
	}

	const Vector4 operator*(float num)
	{
		return Vector4(x * num, y * num, z * num, w * num);
	}

	const Vector4 operator*=(float num)
	{
		return Vector4(x *= num, y *= num, z *= num, w *= num);
	}

	friend Vector4 operator*(float num, Vector4 const &a_oVector)
	{
		return Vector4(a_oVector.x * num, a_oVector.y * num, a_oVector.z * num, a_oVector.w * num);
	}

	const Vector4 operator*(Vector4 const &a_oVector)
	{
		return Vector4(a_oVector.x * x, a_oVector.y * y, a_oVector.z * z, a_oVector.w * w);
	}

	const Vector4 operator*=(Vector4 const &a_oVector)
	{
		return Vector4(x *= a_oVector.x, y *= a_oVector.y, z *= a_oVector.z, w *= a_oVector.w);
	}

private:
	float x;
	float y;
	float z;
	float w;
};

#endif // !__VECTOR4_H__

