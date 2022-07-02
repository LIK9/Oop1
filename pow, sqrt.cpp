#include <iostream>

using namespace std;

int pow(int base, int exponent)
{
	int pow = 1;
	int temp = pow;
	bool overflow = false;
	for (int i = 0; ((i < exponent) && !(overflow)); ++i)
	{
		pow *= base;
		if (pow / base != temp)
			overflow = true;
		temp = pow;
	}
	if (overflow)
		cout << "overflow" << endl;
	else
		return pow;
}

double sqrt(double a)
{
	double b = 0;
	double c = 0;
	b = a / 2;
	while (b != c)
	{
		c = b;
		b = ((a / b) + b) / 2;
	}
	return b;
}

int main()
{
  
  return 0;
}
