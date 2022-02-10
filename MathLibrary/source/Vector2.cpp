////////////////////////////////////////////////////////////
// File: Vector2.h
// Author: Joe Tingle
// Date Created: 24/02/2018
// Brief: Math Library: Vector2 Class with operator overloads
//			Allows for the initalisationa and use of a 2D vector (X,Y)
////////////////////////////////////////////////////////////
///Includes///
#include "../include/Vector2.h"
#include "../include/Utilities.h"
///Includes END///

float Vector2::SquaredDistance(Vector2 &a_oVectorA, Vector2 &a_oVectorB)
{
	float distance = Utilities::SquareRootf(Utilities::Powerf(a_oVectorA.x - a_oVectorB.x, 2) + Utilities::Powerf(a_oVectorA.y - a_oVectorB.y, 2));
	return distance;
}

float Vector2::Distance(Vector2 &a_oVectorA, Vector2 &a_oVectorB)
{
	float distance = (a_oVectorA.x + a_oVectorB.x) + (a_oVectorA.y + a_oVectorB.y);
	return distance;
}

Vector2 Vector2::ZeroVector(Vector2 &a_oVector)
{
	a_oVector.x = 0.f;
	a_oVector.y = 0.f;
	return a_oVector;
}

float Vector2::Magnitude(Vector2 &a_oVector)
{
	float v = Utilities::SquareRootf(Utilities::Powerf(a_oVector.x, 2) + Utilities::Powerf(a_oVector.y, 2));
	return v;
}

Vector2::Vector2()
{
}


Vector2::~Vector2()
{
}

Vector2 Vector2::Normalised(Vector2 &a_oVector)
{
	float magnitude = Magnitude(a_oVector);
	a_oVector.x = a_oVector.x / magnitude;
	a_oVector.y = a_oVector.y / magnitude;
	return a_oVector;
}
Vector2 Vector2::Set(float &a_fX, float &a_fY)
{
	Vector2 vector;
	vector.x = a_fX;
	vector.y = a_fY;
	return vector;
}
Vector2 Vector2::Set(Vector2 &a_oVector)
{
	Vector2 newVector = a_oVector;
	return newVector;
}

bool Vector2::CheckZero(Vector2 &a_oVector)
{
	if (a_oVector.x == 0.0f && a_oVector.y == 0.0f)
	{
		return true;
	}
	return false;
}

bool Vector2::CheckNormalised(Vector2 &a_oVector)
{
	float magnitude = Magnitude(a_oVector);
	if (magnitude == 1)
	{
		return true;
	}
	return false;
}

Vector2 Vector2::Invert(Vector2 &a_oVector)
{
	a_oVector.x = -a_oVector.x;
	a_oVector.y = -a_oVector.y;
	return a_oVector;
}

bool Vector2::IsEqual(Vector2 &a_oVectorA, Vector2 &a_oVectorB)
{
	if (a_oVectorA.x == a_oVectorB.x && a_oVectorA.y == a_oVectorB.y)
	{
		return true;
	}
	return false;
}

Vector2 Vector2::GetLocalCoords(Vector2 &a_oParentVector, Vector2 &a_oLocalVector)
{
	Vector2 LocalCoords;
	LocalCoords.x = a_oLocalVector.x - a_oParentVector.x;
	LocalCoords.y = a_oLocalVector.y - a_oParentVector.y;
	return LocalCoords;

}

Vector2 Vector2::SetLocalCoords(Vector2 &a_oParentVector, Vector2 &a_oLocalVector)
{
	Vector2 LocalCoords;
	LocalCoords.x = x - a_oParentVector.x;
	LocalCoords.y = y - a_oParentVector.y;
	return LocalCoords;

}

Vector2 Vector2::Add(Vector2 &a_oVectorA, Vector2 &a_oVectorB)
{
	Vector2 newVector;
	newVector.x = a_oVectorA.x + a_oVectorB.x;
	newVector.y = a_oVectorA.y + a_oVectorB.y;
	return newVector;
}

Vector2 Vector2::Subtract(Vector2 &a_oVectorA, Vector2 &a_oVectorB)
{
	Vector2 newVector;
	newVector.x = a_oVectorA.x - a_oVectorB.x;
	newVector.y = a_oVectorA.y - a_oVectorB.y;
	return newVector;
}

Vector2 Vector2::Multiply(Vector2 &a_oVectorA, Vector2 &a_oVectorB)
{
	Vector2 newVector;
	newVector.x = a_oVectorA.x * a_oVectorB.x;
	newVector.y = a_oVectorA.y * a_oVectorB.y;
	return newVector;
}

Vector2 Vector2::Multiply(Vector2 &a_oVector, int &a_oScalar)
{
	Vector2 newVector;
	newVector.x = a_oVector.x * a_oScalar;
	newVector.y = a_oVector.y * a_oScalar;
	return newVector;
}


const Vector2 operator-(Vector2 &a, Vector2 &b)
{
	Vector2 returnVector;


	return returnVector;
}

double Vector2::Dot(Vector2 v1, Vector2 v2)
{
	return v1.GetX() * v2.GetX() + v1.GetY() * v2.GetY();
}

double Vector2::Det(Vector2 v1, Vector2 v2)
{
	return v1.GetX() * v2.GetX() - v1.GetY() * v2.GetY();
}

double Vector2::PerpDot(Vector2 left, Vector2 right)
{
	return left.GetX() * right.GetY() - left.GetY() * right.GetX();
}
