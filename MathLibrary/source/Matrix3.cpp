////////////////////////////////////////////////////////////
// File: Matrix3.h
// Author: Joe Tingle
// Date Created: 26/02/2018
// Brief: Math Library: Matrix 3x3 Class allowing you to create
//			a 3x3 matrix with float values and utlise it.
//			has functions for inverting/rotating/determinant etc.
////////////////////////////////////////////////////////////
///Includes
#include "../include/Matrix3.h"
#include "../include/Vector3.h"
#include "../include/Utilities.h"

///Includes END///
void Matrix3::SetMatrix3(Vector3 &a, Vector3 &b, Vector3 &c)
{
	n[0][0] = a.GetX(a);
	n[0][1] = a.GetY(a);
	n[0][2] = a.GetZ(a);
	n[1][0] = b.GetX(b);
	n[1][1] = b.GetY(b);
	n[1][2] = b.GetZ(b);
	n[2][0] = c.GetX(c);
	n[2][1] = c.GetY(c);
	n[2][2] = c.GetZ(c);
}

void Matrix3::ZeroMatrix3(Matrix3 &matrix)
{
	n[0][0] = 0.f;
	n[0][1] = 0.f;
	n[0][2] = 0.f;
	n[1][0] = 0.f;
	n[1][1] = 0.f;
	n[1][2] = 0.f;
	n[2][0] = 0.f;
	n[2][1] = 0.f;
	n[2][2] = 0.f;
}

Matrix3 Matrix3::Add(Matrix3 &a, Matrix3 &b)
{
	Matrix3 matrix;
	matrix.n[0][0] = a.n[0][0] + b.n[0][0];
	matrix.n[0][1] = a.n[0][1] + b.n[0][1];
	matrix.n[0][2] = a.n[0][2] + b.n[0][2];
	matrix.n[1][0] = a.n[1][0] + b.n[1][0];
	matrix.n[1][1] = a.n[1][1] + b.n[1][1];
	matrix.n[1][2] = a.n[1][2] + b.n[1][2];
	matrix.n[2][0] = a.n[2][0] + b.n[2][0];
	matrix.n[2][1] = a.n[2][1] + b.n[2][1];
	matrix.n[2][2] = a.n[2][2] + b.n[2][2];
	return matrix;
}

Matrix3 Matrix3::Subtract(Matrix3 &a, Matrix3 &b)
{
	Matrix3 matrix;
	matrix.n[0][0] = a.n[0][0] - b.n[0][0];
	matrix.n[0][1] = a.n[0][1] - b.n[0][1];
	matrix.n[0][2] = a.n[0][2] - b.n[0][2];
	matrix.n[1][0] = a.n[1][0] - b.n[1][0];
	matrix.n[1][1] = a.n[1][1] - b.n[1][1];
	matrix.n[1][2] = a.n[1][2] - b.n[1][2];
	matrix.n[2][0] = a.n[2][0] - b.n[2][0];
	matrix.n[2][1] = a.n[2][1] - b.n[2][1];
	matrix.n[2][2] = a.n[2][2] - b.n[2][2];
	return matrix;
}

Matrix3 Matrix3::Multiply(Matrix3 &a, Matrix3 &b)
{
	Matrix3 matrix;
	matrix.n[0][0] = a.n[0][0] * b.n[0][0] + a.n[0][1] * b.n[1][0] + a.n[0][2] * b.n[2][0];
	matrix.n[0][1] = a.n[0][0] * b.n[0][1] + a.n[0][1] * b.n[1][1] + a.n[0][2] * b.n[2][1];
	matrix.n[0][2] = a.n[0][0] * b.n[0][2] + a.n[0][1] * b.n[1][2] + a.n[0][2] * b.n[2][2];
	matrix.n[1][0] = a.n[1][0] * b.n[0][0] + a.n[1][1] * b.n[1][0] + a.n[1][2] * b.n[2][0];
	matrix.n[1][1] = a.n[1][0] * b.n[0][1] + a.n[1][1] * b.n[1][1] + a.n[1][2] * b.n[2][1];
	matrix.n[1][2] = a.n[1][0] * b.n[0][2] + a.n[1][1] * b.n[1][2] + a.n[1][2] * b.n[2][2];
	matrix.n[2][0] = a.n[2][0] * b.n[0][0] + a.n[2][1] * b.n[1][0] + a.n[2][2] * b.n[2][0];
	matrix.n[2][1] = a.n[2][0] * b.n[0][1] + a.n[2][1] * b.n[1][1] + a.n[2][2] * b.n[2][1];
	matrix.n[2][2] = a.n[2][0] * b.n[0][2] + a.n[2][1] * b.n[1][2] + a.n[2][2] * b.n[2][2];
	return matrix;
}

Vector3 Matrix3::Multiply(Matrix3 &matrix, Vector3 &vector)
{
	Vector3 returnVector;
	returnVector.Set((matrix.n[0][0] * vector.GetX(vector) + matrix.n[0][1] * vector.GetY(vector) + matrix.n[0][2] * vector.GetZ(vector)),
		(matrix.n[1][0] * vector.GetX(vector) + matrix.n[1][1] * vector.GetY(vector) + matrix.n[1][2] * vector.GetZ(vector)),
		(matrix.n[2][0] * vector.GetX(vector) + matrix.n[2][1] * vector.GetY(vector) + matrix.n[2][2] * vector.GetZ(vector)));
	return returnVector;
}

Matrix3 Matrix3::Multiply(Matrix3 &matrix, int &scalar)
{
	matrix.n[0][0] = matrix.n[0][0] * scalar;
	matrix.n[0][1] = matrix.n[0][1] * scalar;
	matrix.n[0][2] = matrix.n[0][2] * scalar;
	matrix.n[1][0] = matrix.n[1][0] * scalar;
	matrix.n[1][1] = matrix.n[1][1] * scalar;
	matrix.n[1][2] = matrix.n[1][2] * scalar;
	matrix.n[2][0] = matrix.n[2][0] * scalar;
	matrix.n[2][1] = matrix.n[2][1] * scalar;
	matrix.n[2][2] = matrix.n[2][2] * scalar;
	return matrix;
}

float Matrix3::GetDeterminant(Matrix3 &matrix)
{
	float determinant = matrix.n[0][0] * matrix.n[1][1] * matrix.n[2][2] - matrix.n[1][2] * matrix.n[2][1]
		+ matrix.n[0][1] * matrix.n[1][2] * matrix.n[2][0] - matrix.n[1][0] * matrix.n[2][2] + matrix.n[0][2]
		* matrix.n[1][0] * matrix.n[2][1] - matrix.n[1][1] * matrix.n[2][0];
	return determinant;
}

Matrix3 Matrix3::Invert(Matrix3 &matrix)
{
	Vector3 a;
	a.Set(matrix.n[0][0], matrix.n[0][1], matrix.n[0][2]);
	Vector3 b;
	b.Set(matrix.n[1][0], matrix.n[1][1], matrix.n[1][2]);
	Vector3 c;
	c.Set(matrix.n[2][0], matrix.n[2][1], matrix.n[2][2]);

	Vector3 row0;
	row0 = row0.CrossProduct(b, c);

	Vector3 row1;
	row1.CrossProduct(c, a);

	Vector3 row2;
	row2.CrossProduct(a, b);


	float inverseDeterminant = 1.0f / row0.DotProduct(row2, c);

	Matrix3 returnMatrix;
	returnMatrix.n[0][0] = row0.GetX(row0) * inverseDeterminant;
	returnMatrix.n[0][1] = row0.GetY(row0) * inverseDeterminant;
	returnMatrix.n[0][2] = row0.GetZ(row0) * inverseDeterminant;
	returnMatrix.n[1][0] = row1.GetX(row1) * inverseDeterminant;
	returnMatrix.n[1][1] = row1.GetY(row1) * inverseDeterminant;
	returnMatrix.n[1][2] = row1.GetZ(row1) * inverseDeterminant;
	returnMatrix.n[2][0] = row2.GetX(row2) * inverseDeterminant;
	returnMatrix.n[2][1] = row2.GetY(row2) * inverseDeterminant;
	returnMatrix.n[2][2] = row2.GetZ(row2) * inverseDeterminant;
	return returnMatrix;
}

Matrix3 Matrix3::RotateX(float angle)
{
	float c = Utilities::Cosine(angle);
	float s = Utilities::Sine(angle);

	Matrix3 returnMatrix;
	returnMatrix.n[0][0] = 1.f;
	returnMatrix.n[0][1] = 0.f;
	returnMatrix.n[0][2] = 0.f;
	returnMatrix.n[1][0] = 0.f;
	returnMatrix.n[1][1] = c;
	returnMatrix.n[1][2] = -s;
	returnMatrix.n[2][0] = 0.f;
	returnMatrix.n[2][1] = s;
	returnMatrix.n[2][2] = c;
	return returnMatrix;
}

Matrix3 Matrix3::RotateY(float angle)
{
	float c = Utilities::Cosine(angle);
	float s = Utilities::Sine(angle);

	Matrix3 returnMatrix;
	returnMatrix.n[0][0] = c;
	returnMatrix.n[0][1] = 0.f;
	returnMatrix.n[0][2] = s;
	returnMatrix.n[1][0] = 0.f;
	returnMatrix.n[1][1] = 1.f;
	returnMatrix.n[1][2] = 0.f;
	returnMatrix.n[2][0] = -s;
	returnMatrix.n[2][1] = 0.f;
	returnMatrix.n[2][2] = c;
	return returnMatrix;
}

Matrix3 Matrix3::RotateZ(float angle)
{
	float c = Utilities::Cosine(angle);
	float s = Utilities::Sine(angle);

	Matrix3 returnMatrix;
	returnMatrix.n[0][0] = c;
	returnMatrix.n[0][1] = -s;
	returnMatrix.n[0][2] = 0.f;
	returnMatrix.n[1][0] = s;
	returnMatrix.n[1][1] = c;
	returnMatrix.n[1][2] = 0.f;
	returnMatrix.n[2][0] = 0.f;
	returnMatrix.n[2][1] = 0.f;
	returnMatrix.n[2][2] = 1.f;
	return returnMatrix;
}

Matrix3 Matrix3::Rotate(float angle, Vector3 &axis)
{
	float c = Utilities::Cosine(angle);
	float s = Utilities::Sine(angle);
	float d = 1.0f - c;

	float x = axis.GetX(axis) * d;
	float y = axis.GetZ(axis) * d;
	float z = axis.GetZ(axis) * d;

	float aXaY = x * axis.GetY(axis);
	float aXaZ = x * axis.GetZ(axis);
	float aYaZ = y * axis.GetZ(axis);

	Matrix3 returnMatrix;
	returnMatrix.n[0][0] = c + x * axis.GetX(axis);
	returnMatrix.n[0][1] = aXaY - s * axis.GetZ(axis);
	returnMatrix.n[0][2] = aXaZ + s * axis.GetY(axis);
	returnMatrix.n[2][0] = aXaY + s * axis.GetZ(axis);
	returnMatrix.n[2][1] = c + y * axis.GetY(axis);
	returnMatrix.n[2][2] = aYaZ - s * axis.GetX(axis);
	returnMatrix.n[3][0] = aXaZ - s * axis.GetY(axis);
	returnMatrix.n[3][1] = aYaZ + s * axis.GetX(axis);
	returnMatrix.n[3][2] = c + z * axis.GetZ(axis);
	return returnMatrix;
}

Matrix3::Matrix3()
{
}
Matrix3::~Matrix3()
{
}