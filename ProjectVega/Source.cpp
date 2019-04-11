#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Header.h"

extern const long double PI = 3.141592653589793238;

using namespace std;

ofstream outf("vivod.txt");

Function::Function(long double z, long double x, int c)
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
	outf << "Точки интерполяции Чебышева для n=" << n << endl;
	for (int i = 0; i <= n; i++)
	{
		outf << setprecision(19) << "X" << i << "=" <<znaX[i] << "___Y"<< i <<"="<<znaY[i] <<"\n ";
	}
	outf << endl << endl;

	outf << "Коэффициенты многочлена Лагранжа для n=" << n << endl;
	for (int i = 0; i <= n; i++)
	{
		outf << setprecision(19) << "a" << i << "=" << matrix[i][n+1] << "\n";
	}
	outf << endl << endl << endl;
}

void Function::slay()
{
	double buf = 0;
	int i=0,i0=0,i1=0;// переменные для работы циклов

	for (i = 0; i <= n; i++) 
	{
		matrix[i][0] = 1.0;
		matrix[i][1] = znaX[i];

		for (i0 = 2; i0 <= n; i0++)
		{
			matrix[i][i0] = matrix[i][i0 - 1] * znaX[i];
		}
		matrix[i][i0] = znaY[i];
	}
	i = 0; i0 = 0;
	//Прямой метод хода Гаусса 
	for ( i = 0; i <= n-1; i++)// Строка с которой работаем 
	{
		buf = matrix[i][i];
		for ( i0 = i; i0 <= n+1; i0++)//исключаем неизвестную i-того номера
		{
			matrix[i][i0] = matrix[i][i0]/buf;
		}

		for (i0 = i + 1; i0 <= n; i0++)//делим другие строки //номер строки с которой работаем
		{
			buf = matrix[i0][i];
			for (i1 = i; i1 <= n + 1; i1++)// номер столбца
			{
				matrix[i0][i1] = matrix[i0][i1]-(matrix[i][i1]*buf) ;
			}
		}

	}

	//обратный ход метода Гаусаа
	buf = matrix[n][n];
	matrix[n][n] = 1; 
	matrix[n][n + 1] = matrix[n][n + 1] / buf;

	for (i=n;i>=1;i--)
	{
		
		for (i0 = i-1; i0 >= 0; i0--)//делим другие строки //номер строки с которой работаем
		{
			buf = matrix[i0][i];
			matrix[i0][i] = matrix[i0][i] - (matrix[i][i] * buf);
			matrix[i0][n + 1] = matrix[i0][n + 1] - (matrix[i][n + 1] * buf);		
		}
	}
}

