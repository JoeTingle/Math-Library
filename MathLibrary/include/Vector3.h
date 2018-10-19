////////////////////////////////////////////////////////////
// File: Vector3.h
// Author: Joe Tingle
// Date Created: 26/02/2018
// Brief: Math Library: Vector3 Class with operator overloads
//			Allows for the initalisation and use of a 3D vector (X,Y,Z)
//			with function for localcoords/dot/normalised etc.
////////////////////////////////////////////////////////////
#ifndef __VECTOR3_H__
#define __VECTOR3_H__

class Vector3
{
public:
	Vector3();
	~Vector3();

	Vector3(float X, float Y, float Z)
	{
		x = X;
		y = Y;
		z = Z;
	}
	Vector3(Vector3 &vector)
	{
		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	Vector3 Normalised(Vector3 &a_oVector);

	Vector3 ZeroVector(Vector3 &a_oVector);

	Vector3 Set(float x, float y, float z);
	Vector3 Set(Vector3 &a_oVector);

	Vector3 Invert(Vector3 &a_oVector);

	Vector3 GetLocalCoords(Vector3 &a_oParentVector, Vector3 &a_oLocalVector);

	Vector3 Add(Vector3 &a_oVectorA, Vector3 &a_oVectorB);

	Vector3 Subtract(Vector3 &a_oVectorA, Vector3 &a_oVectorB);

	Vector3 Multiply(Vector3 &a_oVectorA, Vector3 &a_oVectorB);
	Vector3 Multiply(Vector3 &a_oVector, int &a_oScalar);
	
	Vector3 CrossProduct(Vector3 &a_oVectorA, Vector3 &a_oVectorB);

	bool isNormalised(Vector3 &a_oVector);
	bool isZero(Vector3 &a_oVector);

	bool isEqual(Vector3 &a_oVectorA, Vector3 &a_oVectorB);

	float SqauredDistance(Vector3 &a_oVectorA, Vector3 &a_oVectorB);
	float Distance(Vector3 &a_oVectorA, Vector3 &a_oVectorB);

	float Magnitude(Vector3 &a_oVector);

	float DotProduct(Vector3 &a_oVectorA, Vector3 &a_oVectorB);

	float GetX(Vector3 &a_oVector);
	float GetY(Vector3 &a_oVector);
	float GetZ(Vector3 &a_oVector);

	const Vector3 operator+(const Vector3 &a_oVector)
	{
		x = x + a_oVector.x;
		y = y + a_oVector.y;
		z = z + a_oVector.z;
		return *this;
	}

	const Vector3 operator+=(const Vector3 &a_oVector)
	{
		x += a_oVector.x;
		y += a_oVector.y;
		z += a_oVector.z;
		return *this;
	}

	const Vector3 operator-(const Vector3 &a_oVector)
	{
		x = x - a_oVector.x;
		y = y - a_oVector.y;
		z = z - a_oVector.z;
		return *this;
	}

	const Vector3 operator-=(const Vector3 &a_oVector)
	{
		x -= a_oVector.x;
		y -= a_oVector.y;
		z -= a_oVector.z;
		return *this;
	}

	const Vector3 operator-()
	{
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}

	const Vector3 operator*(float num)
	{
		x = x * num;
		y = y * num;
		z = z * num;
		return *this;
	}

	const Vector3 operator*=(float num)
	{
		x *= num;
		y *= num;
		z *= num;
		return *this;
	}

	/*friend Vector3 operator*(float num, Vector3 &vector)
	{
		float x = vector.x * num;
		float y = vector.y * num;
		float z = vector.z * num;
		return Vector3(x, y, z);
	}*/

	const Vector3 operator*(Vector3 const &a_oVector)
	{
		x = x * a_oVector.x;
		y = y * a_oVector.y;
		z = z * a_oVector.z;
		return *this;
	}

	const Vector3 operator*=(Vector3 const &a_oVector)
	{
		x *= a_oVector.x;
		y *= a_oVector.y;
		z *= a_oVector.z;
		return *this;
	}

	const bool operator==(Vector3 const &a_oVector)
	{
		if (x == a_oVector.x && y == a_oVector.y && z == a_oVector.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const bool operator!=(Vector3 const &a_oVector)
	{
		if (x != a_oVector.x || y != a_oVector.y || z != a_oVector.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


private:
	float x = 0;
	float y;
	float z;
};

#endif // !__VECTOR3_H__

