#include <conio.h>
#include <iostream>
#include <cmath>
#include <fstream>

#include "Header.h"



using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	

	Function Q1{ 0.0, 1.0, 1.0 };//, Q2{ 0.0,1.0,2.0 }, Q3{ 0.0,1.0,3.0 }, Q4{ 0.0,1.0,4.0 }, Q5{ 0.0,1.0,5.0};
	Q1.chebeshev();
	Q1.out();


	return 0;
}