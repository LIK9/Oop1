#include <iostream>

using namespace std;

int main()
{
	int value1, value2, value3;
	cin >> value1 >> value2 >> value3;
	int min, max;
	if (value1 < value2 && value1 < value3)
	{
		min = value1;
		if (value3 > value2)
			max = value3;
		else
			max = value2;
	}
	else if (value2 < value1 && value2 < value3)
	{
		min = value2;
		if (value3 > value1)
			max = value3;
		else
			max = value1;
	}
	else
	{
		min = value3;
		if (value2 > value1)
			max = value2;
		else
			max = value1;
	}
	cout << min << " " << max << endl;

	return 0;
}
