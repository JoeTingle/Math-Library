////////////////////////////////////////////////////////////
// File: Vector4.h
// Author: Joe Tingle
// Date Created: 26/02/2018
// Brief: Math Library: Basic Vector4 Class with operator overloads
//			Allows for the initalisationa and use of a 4D vector (X,Y,Z,W)
////////////////////////////////////////////////////////////
///Includes///
#include "Vector4.h"
#include "Utilities.h"
///Includes END///


Vector4 Vector4::Normalise(Vector4 &a_oVector)
{
	float magnitude = Magnitude(a_oVector);
	a_oVector.x = a_oVector.x / magnitude;
	a_oVector.y = a_oVector.y / magnitude;
	a_oVector.z = a_oVector.z / magnitude;
	a_oVector.w = a_oVector.w / magnitude;
	return a_oVector;
}

float Vector4::Magnitude(Vector4 &a_oVector)
{
	float v = Utilities::SquareRootf(Utilities::Powerf(a_oVector.x, 2) + Utilities::Powerf(a_oVector.y, 2) + Utilities::Powerf(a_oVector.z, 2) + Utilities::Powerf(a_oVector.w, 2));
	return v;
}

float Vector4::DotProduct(Vector4 &a_oVectorA, Vector4 &a_oVectorB)
{
	return (a_oVectorA.x*a_oVectorB.x) + (a_oVectorA.y*a_oVectorB.y) + (a_oVectorA.z*a_oVectorB.z) + (a_oVectorA.w+ a_oVectorB.w);
}

Vector4::~Vector4()
{
}