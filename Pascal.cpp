#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "enter n in (x + y)^n : ";
	cin >> n;

	int** pascal = new int* [n + 1];
	for (int i = 0; i < n + 1; ++i)
		pascal[i] = new int[i + 1];

	for (int r = 0; r < n + 1; ++r)
	{
		for (int c = 0; c < r + 1; ++c)
		{
			if (c == 0 || r == c)
				pascal[r][c] = 1;
			else
				pascal[r][c] = pascal[r - 1][c] + pascal[r - 1][c - 1];
		}
	}
	cout << "binary coefficient of (x + y)^" << n << " : ";
	for (int i = 0; i < n + 1; ++i)
		cout << pascal[n][i] << " ";
	cout << endl;

	for (int i = 0; i < n + 1; ++i)
		delete[] pascal[i];
	delete[] pascal;

	return 0;
}
