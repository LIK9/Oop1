#include <iostream>
#include <iomanip>

using namespace  std;

class Matrix
{
private:
	int m_row;
	int m_col;
	int** m_m;
public:
	Matrix(int, int);
	~Matrix();
	void setup();
	void print() const;
	void add(const Matrix& second, Matrix& result) const;
	void sub(const Matrix& second, Matrix& result) const;
	void mul(const Matrix& second, Matrix& result) const;
};

Matrix::Matrix(int row, int col)
	: m_row(row), m_col(col)
{
	m_m = new int* [row];
	for (int i = 0; i < m_row; ++i)
		m_m[i] = new int[col];
}

Matrix::~Matrix()
{
	for (int i = 0; i < m_row; ++i)
		delete[] m_m[i];
	delete[] m_m;
}

void Matrix::setup()
{
	for (int r = 0; r < m_row; ++r)
	{
		for (int c = 0; c < m_col; ++c)
		{
			m_m[r][c] = rand() % 5 + 1;
		}
	}
}

void Matrix::print() const
{
	for (int r = 0; r < m_row; ++r)
	{
		for (int c = 0; c < m_col; ++c)
		{
			cout << setw(5) << m_m[r][c];
		}
		cout << endl;
	}
}

void Matrix::add(const Matrix& second, Matrix& result) const
{
	for (int r = 0; r < m_row; ++r)
	{
		for (int c = 0; c < m_col; ++c)
		{
			result.m_m[r][c] = m_m[r][c] + second.m_m[r][c];
		}
	}
}

void Matrix::sub(const Matrix& second, Matrix& result) const
{
	for (int r = 0; r < m_row; ++r)
	{
		for (int c = 0; c < m_col; ++c)
		{
			result.m_m[r][c] = m_m[r][c] - second.m_m[r][c];
		}
	}
}

void Matrix::mul(const Matrix& second, Matrix& result) const
{
	for (int r = 0; r < result.m_row; ++r)
	{
		for (int c = 0; c < result.m_col; ++c)
		{
			result.m_m[r][c] = 0;
			for (int i = 0; i < m_col; ++i)
			{
				result.m_m[r][c] += (m_m[r][i] * second.m_m[i][c]);
			}
		}
	}
}

int main()
{	
	cout << "m1" << endl;
	Matrix m1(3, 4);
	m1.setup();
	m1.print();

	cout << "m2" << endl;
	Matrix m2(3, 4);
	m2.setup();
	m2.print();

	cout << "m3" << endl;
	Matrix m3(4, 2);
	m3.setup();
	m3.print();

	cout << "m1 + m2" << endl;
	Matrix add(3, 4);
	m1.add(m2, add);
	add.print();

	cout << "m1 - m2" << endl;
	Matrix sub(3, 4);
	m1.sub(m2, sub);
	sub.print();

	cout << "m1 * m3" << endl;
	Matrix mul(3, 2);
	m1.mul(m3, mul);
	mul.print();

	return 0;
}
