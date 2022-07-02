#include <iostream>

using namespace std;

int main()
{
  int a = 123;
	int b = 0;
	while (a != 0)
	{	
		b *= 10;
		b += a % 10;
		a /= 10;
	}
	cout << b << endl;
  
  return 0;
}
