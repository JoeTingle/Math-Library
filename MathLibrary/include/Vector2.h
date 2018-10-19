////////////////////////////////////////////////////////////
// File: Vector2.h
// Author: Joe Tingle
// Date Created: 24/02/2018
// Brief: Math Library: Vector2 Class with operator overloads
//			Allows for the initalisationa and use of a 2D vector (X,Y)
////////////////////////////////////////////////////////////
#ifndef __VECTOR2_H__
#define __VECTOR2_H__
class Vector2
{
public:
	Vector2();
	~Vector2();

	Vector2(float X, float Y) // Allows initialisation from 2 float values
	{
		x = X;
		y = Y;
	}
	Vector2(const Vector2 &a_oVector)//Allows initialisation from an exisiting vector
	{
		x = a_oVector.x;
		y = a_oVector.y;
	}

	Vector2 Normalised(Vector2 &a_oVector); // Normalises the given vector
	Vector2 ZeroVector(Vector2 &a_oVector); //Will create and return vector(0,0)
	Vector2 Set(float &a_fX, float &a_fY); // Creates and returns a vector with given float values
	Vector2 Set(Vector2 &a_oVector);// Creates and returns a vector with the given vector
	Vector2 Invert(Vector2 &a_oVector);//Will invert the vector and then return it
	Vector2 GetLocalCoords(Vector2 &a_oParentVector, Vector2 &a_oLocalVector);// Calculates the local coords of the object relative to the given parent and return them
	Vector2 Add(Vector2 &a_oVectorA, Vector2 &a_oVectorB);// Adds two given vectors together
	Vector2 Subtract(Vector2 &a_oVectorA, Vector2 &a_oVectorB);//Subtracts two given vectors and returns new value
	Vector2 Multiply(Vector2 &a_oVectorA, Vector2 &a_oVectorB);//Mutliplies two given vectors
	Vector2 Multiply(Vector2 &a_oVector, int &a_oScalar);//Multiplies given vector by scalar and returns
	Vector2 SetLocalCoords(Vector2 &a_oParentVector, Vector2 &a_oLocalVector);//Calculates local coords and sets them

	bool CheckNormalised(Vector2 &a_oVector);//Returns true if the vector is normalised e.gVector2(1,0)
	bool CheckZero(Vector2 &a_oVector);//Returns true if vector is zero e.g vector2(0,0)
	bool IsEqual(Vector2 &a_oVectorA, Vector2 &a_oVectorB);//Returns true if both vectors are identical

	float SquaredDistance(Vector2 &a_oVectorA, Vector2 &a_oVectorB);//Calculates and returns the sqaured distance between two given vectors
	float Distance(Vector2 &a_oVectorA, Vector2 &a_oVectorB);//Calculates and returns the standard distance between two given vectors
	float Magnitude(Vector2 &a_oVector);//Calculates magnitude of vector

	static double Dot(Vector2 v1, Vector2 v2);//Calculates and returns Dot Product
	static double Det(Vector2 v1, Vector2 v2);//Calculates the determinant of the vectors
	static double Dot(Vector2 v2);
	static double PerpDot(Vector2 left, Vector2 right);

	//Getters for x/y
	float GetX() { return x; }
	float GetY() { return y; }

	//Setters for x/y
	void SetX(float X) { x = X; }
	void SetY(float Y) { y = Y; }

	///////////////////////
	//Operator Overloads //
	const Vector2 operator+(const Vector2 &a_oVector)
	{
		x = x + a_oVector.x;
		y = y + a_oVector.y;
		return *this;
	}

	const Vector2 operator+=(const Vector2 &a_oVector)
	{
		x += a_oVector.x;
		y += a_oVector.y;
		return *this;
	}

	const Vector2 operator-(const Vector2 &a_oVector)
	{
		x = x - a_oVector.x;
		y = y - a_oVector.y;
		return *this;
	}

	const Vector2 operator-=(const Vector2 &a_oVector)
	{
		x -= a_oVector.x;
		y -= a_oVector.y;
		return *this;
	}

	const Vector2 operator-()
	{
		x = -x;
		y = -y;
		return *this;
	}

	const Vector2 operator*(float num)
	{
		x = x * num;
		y = y * num;
		return *this;
	}

	const Vector2 operator*=(float num)
	{
		x *= num;
		y *= num;
		return *this;
	}

	friend Vector2 operator*(const Vector2 &a_oVector, const float num)
	{
		Vector2 vec;
		vec.x = a_oVector.x * num;
		vec.y = a_oVector.y * num;
		return vec;
	}

	const Vector2 operator*(Vector2 const &a_oVector)
	{
		x = x * a_oVector.x;
		y = y * a_oVector.y;
		return *this;
	}

	const Vector2 operator*=(Vector2 const &a_oVector)
	{
		x *= a_oVector.x;
		y *= a_oVector.y;
		return *this;
	}

	const Vector2 operator/(Vector2 const &a_oVector)
	{
		x = x / a_oVector.x;
		y = y / a_oVector.y;
		return *this;
	}

	const Vector2 operator/=(Vector2 const &a_oVector)
	{
		x /= a_oVector.x;
		y /= a_oVector.y;
		return *this;
	}

	const Vector2 operator/(float &num)
	{
		x = x / num;
		y = y / num;
		return *this;
	}

	const Vector2 operator/=(float &num)
	{
		x /= num;
		y /= num;
		return *this;
	}

	friend Vector2 operator/(const Vector2 &a_oVector, const float num)
	{
		Vector2 vec;
		vec.x = a_oVector.x / num;
		vec.y = a_oVector.y / num;
		return vec;
	}

	const bool operator==(Vector2 const &a_oVector)
	{
		if (x == a_oVector.x && y == a_oVector.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const bool operator!=(Vector2 const &a_oVector)
	{
		if (x != a_oVector.x || y != a_oVector.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	float x;
	float y;
};




#endif // !__VECTOR2_H__
