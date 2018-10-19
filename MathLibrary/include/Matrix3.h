////////////////////////////////////////////////////////////
// File: Matrix3.h
// Author: Joe Tingle
// Date Created: 26/02/2018
// Brief: Math Library: Matrix 3x3 Class allowing you to create
//			a 3x3 matrix with float values and utlise it.
//			has functions for inverting/rotating/determinant etc.
////////////////////////////////////////////////////////////
#ifndef __MATRIX3_H__
#define __MATRIX3_H__



#include "Matrix3.h"
#include "Vector3.h"
//3x3 Matrix Class
class Matrix3
{
public:
	Matrix3();
	~Matrix3();

	//Referenced from Eric lengyel's Foundations Of Game Engine Development, Volume 1 Pg.15
	Matrix3(float node00, float node01, float node02, float node10, float node11, float node12, float node20, float node21, float node22)
	{
		n[0][0] = node00;
		n[0][1] = node01;
		n[0][2] = node02;
		n[1][0] = node10;
		n[1][1] = node11;
		n[1][2] = node12;
		n[2][0] = node20;
		n[2][1] = node21;
		n[2][2] = node22;
	}
	Matrix3(Vector3 &a, Vector3 &b, Vector3 &c)
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

	void SetMatrix3(Vector3 &a, Vector3 &b, Vector3 &c);
	void ZeroMatrix3(Matrix3 &matrix);

	Matrix3 Add(Matrix3 &a, Matrix3 &b);
	Matrix3 Subtract(Matrix3 &a, Matrix3 &b);
	Matrix3 Multiply(Matrix3 &a, Matrix3 &b);
	Vector3 Multiply(Matrix3 &matrix, Vector3 &vector);
	Matrix3 Multiply(Matrix3 &matrix, int &scalar);
	Matrix3 Invert(Matrix3 &matrix);
	Matrix3 RotateX(float angle);
	Matrix3 RotateY(float angle);
	Matrix3 RotateZ(float angle);
	Matrix3 Rotate(float angle, Vector3 &axis);

	float GetDeterminant(Matrix3 &matrix);

	const Matrix3 operator+(const Matrix3 &matrix)
	{
		return Matrix3(n[0][0] + matrix.n[0][0], n[0][1] + matrix.n[0][1], n[0][2] + matrix.n[0][2], 
			n[1][0] + matrix.n[1][0], n[1][1] + matrix.n[1][1], n[1][2] + matrix.n[1][2]
			,n[2][0] + matrix.n[2][0], n[2][1] + matrix.n[2][1], n[2][2] + matrix.n[2][2]);
	}

	const Matrix3 operator-(const Matrix3 &matrix)
	{
		return Matrix3(n[0][0] - matrix.n[0][0], n[0][1] - matrix.n[0][1], n[0][2] - matrix.n[0][2],
			n[1][0] - matrix.n[1][0], n[1][1] - matrix.n[1][1], n[1][2] - matrix.n[1][2]
			, n[2][0] - matrix.n[2][0], n[2][1] - matrix.n[2][1], n[2][2] - matrix.n[2][2]);
	}

	const Matrix3 operator-()
	{
		return Matrix3(-n[0][0], -n[0][1], -n[0][2], -n[1][0], -n[1][1], -n[2][2], -n[2][0], -n[2][1], -n[2][2]);
	}

	const Matrix3 operator*(float scalar)
	{
		return Matrix3(n[0][0] * scalar, n[0][1] * scalar, n[0][2] * scalar
		, n[1][0] * scalar, n[1][1] * scalar, n[1][2] * scalar
		, n[2][0] * scalar, n[2][1] * scalar, n[2][2] * scalar);
	}

	friend Matrix3 operator*(float scalar, Matrix3 const &matrix)
	{
		return Matrix3(matrix.n[0][0] * scalar, matrix.n[0][1] * scalar, matrix.n[0][2] * scalar
			, matrix.n[1][0] * scalar, matrix.n[1][1] * scalar, matrix.n[1][2] * scalar
			, matrix.n[2][0] * scalar, matrix.n[2][1] * scalar, matrix.n[2][2] * scalar);
	}

	const Matrix3 operator*(Matrix3 const &matrix)
	{
		return Matrix3(n[0][0] * matrix.n[0][0] + n[0][1] * matrix.n[1][0] + n[0][2] * matrix.n[2][0],
						n[0][0] * matrix.n[0][1] + n[0][1] * matrix.n[1][1] + n[0][2] * matrix.n[2][1],
						n[0][0] * matrix.n[0][2] + n[0][1] * matrix.n[1][2] + n[0][2] * matrix.n[2][2],
						n[1][0] * matrix.n[0][0] + n[1][1] * matrix.n[1][0] + n[1][2] * matrix.n[2][0],
						n[1][0] * matrix.n[0][1] + n[1][1] * matrix.n[1][1] + n[1][2] * matrix.n[2][1],
						n[1][0] * matrix.n[0][2] + n[1][1] * matrix.n[1][2] + n[1][2] * matrix.n[2][2],
						n[2][0] * matrix.n[0][0] + n[2][1] * matrix.n[1][0] + n[2][2] * matrix.n[2][0],
						n[2][0] * matrix.n[0][1] + n[2][1] * matrix.n[1][1] + n[2][2] * matrix.n[2][1],
						n[2][0] * matrix.n[0][2] + n[2][1] * matrix.n[1][2] + n[2][2] * matrix.n[2][2]);
	}

	const bool operator==(Matrix3 const &matrix)
	{
		if (matrix.n[0][0] == n[0][0] && matrix.n[0][1] == n[0][1] && matrix.n[0][2] == n[0][2] && 
			matrix.n[1][0] == n[1][0] && matrix.n[1][1] == n[1][1] && matrix.n[1][2] == n[1][2] && 
			matrix.n[2][0] == n[2][0] && matrix.n[1][1] == n[1][1] && matrix.n[2][2] == n[2][2])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const bool operator!=(Matrix3 const &matrix)
	{
		if (matrix.n[0][0] != n[0][0] || matrix.n[0][1] != n[0][1] || matrix.n[0][2] != n[0][2] ||
			matrix.n[1][0] != n[1][0] || matrix.n[1][1] != n[1][1] || matrix.n[1][2] != n[1][2] ||
			matrix.n[2][0] != n[2][0] || matrix.n[1][1] != n[1][1] || matrix.n[2][2] != n[2][2])
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	//Creating 2D array for matrix 3x3
	float n[3][3];
};

#endif // !__MATRIX3_H__

