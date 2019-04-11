#include <iostream>
#include <locale.h>
#include <cmath>

#include "Header.h"



using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	

	Function Q1{ 0.0, 1.0, 1}, Q2{ 0.0,1.0,2}, Q3{ 0.0,1.0,3}, Q4{ 0.0,1.0,4},Q5{ 0.0,1.0,5};
	Q1.chebeshev();
	Q1.slay();
	Q1.out();

	Q2.chebeshev();
	Q2.slay();
	Q2.out();

	Q3.chebeshev();
	Q3.slay();
	Q3.out();

	Q4.chebeshev();
	Q4.slay();
	Q4.out();

	Q5.chebeshev();
	Q5.slay();
	Q5.out();

	return 0;
}