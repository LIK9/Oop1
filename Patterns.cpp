#include <iostream>

using namespace std;

int main()
{
  for (int i1 = 1; i1 <= 5; ++i1)
	{
		for (int i2 = 0; i2 < i1; ++i2)
		{
			cout << '*';
		}
		cout << endl;
	}

	cout << endl;

	for (int i1 = 5; i1 >= 1; --i1)
	{
		for (int i2 = 5; i2 > i1; --i2)
		{
			cout << " ";
		}
		for (int i3 = 0; i3 < i1; ++i3)
		{
			cout << '*';
		}
		cout << endl;
	}
	
	cout << endl;
	
	for (int i1 = 1; i1 <= 5; ++i1)
	{	
		for (int i2 = 5; i2 > i1; --i2)
		{
			cout << " ";
		}
		for (int i3 = 0; i3 < i1; ++i3)
		{
			cout << '*';
		}
		cout << endl;
	}
		
	cout << endl;
	
	for (int i1 = 5; i1 >= 1; --i1)
	{
		for (int i2 = 5; i2 > i1; --i2)
		{
			cout << " ";
		}
		for (int i3 = 0; i3 < i1; ++i3)
		{
			cout << '*';
		}
		for (int i3 = 1; i3 < i1; ++i3)
		{
			cout << '*';
		}
		cout << endl;
	}



	for (int i1 = 1; i1 <= 5; ++i1)
	{	
		for (int i2 = 5; i2 > i1; --i2)
		{
			cout << " ";
		}
		for (int i3 = 0; i3 < i1; ++i3)
		{
			cout << '*';
		}
		for (int i4 = 1; i4 < i1; ++i4)
		{
			cout << '*';
		}
		cout << endl;
	}
  
  return 0;
}
