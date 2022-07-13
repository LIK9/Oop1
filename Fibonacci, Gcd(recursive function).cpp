#include <iostream>

using namespace std;

int fibonacci(int a)
{
	if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	return fibonacci(a - 1) + fibonacci(a - 2);
}

int gcd(int a, int b)
{	
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
  
  return 0;
}
