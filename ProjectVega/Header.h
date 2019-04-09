#ifndef HEADER_H
#define HEADER_H

class Function
{
	long double a, b, n;
	long double znaX[10], znaY[10], matrix[10][10];

	public:
		Function(long double z, long double x, long double c);
		void chebeshev();
		void out();
		void slay();

};

#endif
