////////////////////////////////////////////////////////////
// File: Utilities.h
// Author: Joe Tingle
// Date Created: 13/05/2018
// Brief: Math Library: Utilities Class for custom math methods
//			such as square root/Power/Rounding etc. instead of using std math library
////////////////////////////////////////////////////////////
#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#define PI 3.14159265359
static class Utilities
{
public:
	Utilities();
	~Utilities();

	static float SquareRootf(float a_fNum);
	static float Powerf(float a_fNum, float a_fToPowerOf);

	static float Factorial(int a_iNumber);

	static float Sine(int a_iDegrees);
	static float Cosine(int a_iDegrees);

	static int Ceil(float a_fNum);
	static int Floor(float a_fNum);


};
#endif // !__UTILITIES_H__

