#pragma once
#include <iostream>



class Calculator
{
	static void Not_supported() { std::cout << "\n" << "This type of data is not supported"; }
public:
	// testing zone------------------------------------------------------------------
	
	//template <typename Type_any> 
	//static void Summation(Type_any Operand_1, Type_any Operand_2)
	//static Type_any Summation(Type_any Operand_1, Type_any Operand_2) { Not_supported(); }
	//template <> 
	//static long long Summation <long long>(long long Operand_1, long long Operand_2)	{ return Operand_1 + Operand_2; }
	
	//static long long Summation (long long Operand_1, long long Operand_2) { return Operand_1 + Operand_2; }
	
	//static size_t Summation(size_t Operand_1, size_t Operand_2) { return Operand_1 + Operand_2; }

	//static int Summation(int Operand_1, int Operand_2) { return Operand_1 + Operand_2; }

	//static long double Summation(long double Operand_1, long double Operand_2)	{ return Operand_1 + Operand_2; }

	static double Summation( double Operand_1,  double Operand_2) { return Operand_1 + Operand_2; }

	
	//Substract---------------------------------------------------------------------
	static double Substract(double Operand_1, double Operand_2) { return Operand_1 - Operand_2; }	
	static double Multiply(double Operand_1, double Operand_2) { return Operand_1 * Operand_2; }
	static double Divide(double Operand_1, double Operand_2) { return Operand_1 / Operand_2; }
	//returns how much Operand 1 is greater then Operand_2 in procent
	static double Percentage(double Operand_1, double Operand_2)	{ return ((Operand_2 /Operand_1) * 100); }
};