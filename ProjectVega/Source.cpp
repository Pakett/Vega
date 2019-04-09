#include <iostream>
#include <conio.h>
#include <cmath>
#include <fstream>

#include "Header.h"

extern const long double PI = 3.141592653589793238;

using namespace std;

ofstream outf("vivod.txt");

Function::Function(long double z, long double x, long double c)
{
	a = z; b = x; n = c;
	

}

void Function::chebeshev()
{

	for (int i = 0; i <= n; i++) {
		long double polinom;

		polinom = ((a + b) / 2) + (((b - a) / 2)*cos(((2 * i + 1)* PI) / (2 * (n + 1))));// для получения нужного количества точек мы не понижаем n на единицу
		znaX[i] = polinom;
		znaY[i] = log(1 + polinom);
	};
}
void Function::out()
{
	outf << "Точки интерополяции для n=" << n << endl;
	for (int i = 0; i <= n; i++)
	{
		outf << "X" << i << "=" << znaX[i] << " ";
	}
	outf << endl;
}

void Function::slay()
{
	for (int i = 0; i <= n; i++)
	{
		matrix[i][0] = 1.0;
		for (int ii = 1; ii <= n; ii++)
		{
			matrix[i][ii] = matrix[i][ii - 1] * znaX[i];
		}
		matrix[i][i + 1] = znaY[i];
	}

}