////////////////////////////////////////////////////////////
// File: Vector3.h
// Author: Joe Tingle
// Date Created: 26/02/2018
// Brief: Math Library: Vector3 Class with operator overloads
//			Allows for the initalisation and use of a 3D vector (X,Y,Z)
//			with function for localcoords/dot/normalised etc.
////////////////////////////////////////////////////////////
///Includes///
#include "../include/Vector3.h"
#include "../include/Utilities.h"
///Includes END///
Vector3 Vector3::Normalised(Vector3 &a_oVector)
{
	float magnitude = Magnitude(a_oVector);
	a_oVector.x = a_oVector.x / magnitude;
	a_oVector.y = a_oVector.y / magnitude;
	a_oVector.z = a_oVector.z / magnitude;
	return a_oVector;
}

float Vector3::Magnitude(Vector3 &a_oVector)
{
	float v = Utilities::SquareRootf(Utilities::Powerf(a_oVector.x, 2) + Utilities::Powerf(a_oVector.y, 2) + Utilities::Powerf(a_oVector.z, 2));
	return v;
}

Vector3 Vector3::ZeroVector(Vector3 &a_oVector)
{
	a_oVector.x = 0.f;
	a_oVector.y = 0.f;
	a_oVector.z = 0.f;
	return a_oVector;
}

Vector3 Vector3::Set(float x, float y, float z)
{
	Vector3 vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	return vector;
}

Vector3 Vector3::Set(Vector3 &a_oVector)
{
	Vector3 newVector = a_oVector;
	return newVector;
}

Vector3 Vector3::Invert(Vector3 &a_oVector)
{
	a_oVector.x = -a_oVector.x;
	a_oVector.y = -a_oVector.y;
	a_oVector.z = -a_oVector.z;
	return a_oVector;
}

Vector3 Vector3::GetLocalCoords(Vector3 &a_oParentVector, Vector3 &a_oLocalVector)
{
	Vector3 LocalCoords;
	LocalCoords.x = a_oLocalVector.x - a_oParentVector.x;
	LocalCoords.y = a_oLocalVector.y - a_oParentVector.y;
	LocalCoords.z = a_oLocalVector.z - a_oParentVector.z;
	return LocalCoords;
}

Vector3 Vector3::Add(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	Vector3 newVector;
	newVector.x = a_oVectorA.x + a_oVectorB.x;
	newVector.y = a_oVectorA.y + a_oVectorB.y;
	newVector.z = a_oVectorA.z + a_oVectorB.z;
	return newVector;
}

Vector3 Vector3::Subtract(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	Vector3 newVector;
	newVector.x = a_oVectorA.x - a_oVectorB.x;
	newVector.y = a_oVectorA.y - a_oVectorB.y;
	newVector.z = a_oVectorA.z - a_oVectorB.z;
	return newVector;
}

Vector3 Vector3::Multiply(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	Vector3 newVector;
	newVector.x = a_oVectorA.x * a_oVectorB.x;
	newVector.y = a_oVectorA.y * a_oVectorB.y;
	newVector.z = a_oVectorA.z * a_oVectorB.z;
	return newVector;
}

Vector3 Vector3::Multiply(Vector3 &a_oVector, int &a_oScalar)
{
	Vector3 newVector;
	newVector.x = a_oVector.x * a_oScalar;
	newVector.y = a_oVector.y * a_oScalar;
	newVector.z = a_oVector.z * a_oScalar;
	return newVector;
}

bool Vector3::isNormalised(Vector3 &a_oVector)
{
	float magnitude = Magnitude(a_oVector);
	if (magnitude == 1)
	{
		return true;
	}
	return false;
}

bool Vector3::isZero(Vector3 &a_oVector)
{
	if (a_oVector.x == 0.0f && a_oVector.y == 0.0f && a_oVector.z == 0.0f)
	{
		return true;
	}
	return false;
}

bool Vector3::isEqual(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	if (a_oVectorA.x == a_oVectorB.x && a_oVectorA.y == a_oVectorB.y && a_oVectorA.z == a_oVectorB.z)
	{
		return true;
	}
	return false;
}

float Vector3::SqauredDistance(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	float distance = Utilities::SquareRootf(Utilities::Powerf(a_oVectorA.x - a_oVectorB.x, 2) + Utilities::Powerf(a_oVectorA.y - a_oVectorB.y, 2) + Utilities::Powerf(a_oVectorA.z - a_oVectorB.z, 2));
	return distance;
}

float Vector3::Distance(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	float distance = (a_oVectorA.x + a_oVectorB.x) + (a_oVectorA.y + a_oVectorB.y) + (a_oVectorA.z + a_oVectorB.z);
	return distance;
}

float Vector3::GetX(Vector3 &a_oVector)
{
	return a_oVector.x;
}
float Vector3::GetY(Vector3 &a_oVector)
{
	return a_oVector.y;
}
float Vector3::GetZ(Vector3 &a_oVector)
{
	return a_oVector.z;
}

float Vector3::DotProduct(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	return (a_oVectorA.x*a_oVectorB.x) + (a_oVectorA.y*a_oVectorB.y) + (a_oVectorA.z*a_oVectorB.z);
}

Vector3 Vector3::CrossProduct(Vector3 &a_oVectorA, Vector3 &a_oVectorB)
{
	Vector3 crossProduct;
	crossProduct.x = a_oVectorA.y * a_oVectorB.z - a_oVectorA.z * a_oVectorB.y;
	crossProduct.y = a_oVectorA.z * a_oVectorB.x - a_oVectorA.x * a_oVectorB.z;
	crossProduct.z = a_oVectorA.x * a_oVectorB.y - a_oVectorA.y * a_oVectorB.x;
	return crossProduct;
}

Vector3::Vector3()
{
}

Vector3::~Vector3()
{
}
