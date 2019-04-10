#ifndef HEADER_H
#define HEADER_H

class Function
{
	long double a, b;
	int n;
	long double znaX[7], znaY[7], matrix[7][8];

	public:
		Function(long double z, long double x, int c);
		void chebeshev();
		void out();
		void slay();

};

#endif
