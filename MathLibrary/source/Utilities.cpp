////////////////////////////////////////////////////////////
// File: Utilities.cpp
// Author: Joe Tingle
// Date Created: 13/05/2018
// Brief: Math Library: Utilities Class for custom math methods
//			such as square root etc. instead of using std math library
////////////////////////////////////////////////////////////
#include "../include/Utilities.h"
#include <iostream>



Utilities::Utilities()
{
}

Utilities::~Utilities()
{
}

float Utilities::SquareRootf(float a_fNum) //Babylonian method of calculating square root
{
	float x = a_fNum;
	float y = 1;
	float a = 0.001; //Used For Accuracy (WARNING : can cause program to hang and not load if too accurates)
	while ((x-y) > a)
	{
		x = (x + y) / 2;
		y = a_fNum / x;
	}

	return x;
}

float Utilities::Powerf(float a_fNum, float a_fToPowerOf)
{
	if (a_fToPowerOf < 0) 
	{
		if (a_fNum == 0)
		{
			return -1; // return error number
		}
		return 1 / (a_fNum * Utilities::Powerf(a_fNum, (-a_fToPowerOf) - 1));
	}
	if (a_fToPowerOf == 0)
	{
		return 1;
	}
	if (a_fToPowerOf == 1)
	{
		return a_fNum;
	}
	return a_fNum * Utilities::Powerf(a_fNum, a_fToPowerOf - 1);
}

float Utilities::Factorial(int a_iNumber)
{
	return a_iNumber <= 0 ? 1 : a_iNumber * Utilities::Factorial(a_iNumber - 1);
}

float Utilities::Sine(int a_iDegrees) // Using Taylor Series
{
	a_iDegrees %= 360; // Ensuring it is within 360 degrees
	float rad = a_iDegrees * PI / 180;
	float sin = 0; // Creating return variable and initialising it

	for (int i = 0; i < 7; i++) 
	{ 
		sin += Utilities::Powerf(-1, i) * Utilities::Powerf(rad, 2 * i + 1) / Utilities::Factorial(2 * i + 1);
	}
	return sin;
}

float Utilities::Cosine(int a_iDegrees)// Also Using Taylor Series
{
	a_iDegrees %= 360; /// Ensuring it is within 360 degrees
	float rad = a_iDegrees * PI / 180;
	float cos = 0; // Creating return variable and initialising it

	for (int i = 0; i < 7; i++) 
	{
		cos += Utilities::Powerf(-1, i) * Utilities::Powerf(rad, 2 * i) / Utilities::Factorial(2 * i);
	}
	return cos;
}

int Utilities::Ceil(float a_fNum)
{
	a_fNum = (int)(a_fNum + 1);
	return a_fNum;
}
int Utilities::Floor(float a_fNum)
{
	(int)a_fNum;
	return a_fNum;
}


void WelcomeToMyPortfolio(int &username)
{
	std::cout << "Hello " << username << " , welcome to my portfolio !" << std::endl;
}