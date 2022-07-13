#include <iostream> 
#include <array>
#include <iomanip>

using namespace std;

class GradeBook
{
public:
	static const size_t row = 10;
	const static size_t col = 3;

	GradeBook(const array<array<int, col>, row>& std)
		: m_std(std)
	{}

	void print() const
	{
		printScore();
		cout << endl;
		cout << "min: " << getMin() << endl;
		cout << "max: " << getMax() << endl;
		cout << endl;
		printChart();
	}

	double getTstAvg(const array<int, col>& std) const
	{
		int sum = 0;
		for (const int& ele : std)
			sum += ele;
		return static_cast<double>(sum) / col;
	}

	void getStdAvg(const array<array<int, col>, row>& std, array<double, col>& stdAvg) const
	{
		for (int c = 0; c < col; ++c)
		{
			for (int r = 0; r < row; ++r)
			{
				stdAvg[c] += std[r][c];
			}
			stdAvg[c] /= row;
		}
	}

	void printScore() const
	{	
		cout << "	  ";
		for (int i = 1; i <= col; ++i)
			cout << setw(7) << "Test " << i;
		cout << "  Average" << endl;

		for (int r = 0; r < row; ++r)
		{	
			cout << "Student " << setw(2) << r + 1;
			for (int c = 0; c < col; ++c)
			{
				cout << setw(8) << m_std[r][c];
			}
			double tavg = getTstAvg(m_std[r]);
			cout << setw(9) << fixed << setprecision(2) << tavg << endl;
		}

		array<double, col> stdAvg{};
		getStdAvg(m_std, stdAvg);
		cout << "Average   ";
		for (int c = 0; c < col; ++c)
			cout << setw(8) << stdAvg[c];
		cout << endl;
	}

	void printChart() const
	{
		const size_t freSize = 11;
		array<int, freSize> fre{};
		for (const array<int, col>& row : m_std)
		{
			for (const int& ele : row)
			{
				++fre[ele / 10];
			}
		}
		for (int i = 0; i < fre.size(); ++i)
		{
			if (i == 0)
				cout << "  0-9: ";
			else if (i == 10)
				cout << "  100: ";
			else
				cout << i * 10 << '-' << i * 10 + 9 << ": ";
			for (int j = 0; j < fre[i]; ++j)
				cout << '*';
			cout << endl;
		}
	}

	int getMin() const
	{	
		int min = m_std[0][0];
		for (int r = 0; r < m_std.size(); ++r)
		{
			for (int c = 0; c < m_std[r].size(); ++c)
			{
				if (min > m_std[r][c])
					min = m_std[r][c];
			}
		}
		return min;
	}

	int getMax() const
	{
		int max = m_std[0][0];
		for (int r = 0; r < m_std.size(); ++r)
		{
			for (int c = 0; c < m_std[r].size(); ++c)
			{
				if (max < m_std[r][c])
					max = m_std[r][c];
			}
		}
		return max;
	}

private:
	array<array<int, col>, row> m_std{};
};

int main()
{	
	array<array<int, GradeBook::col>, GradeBook::row> std =
	{ {
		{87, 96, 70},
		{68, 87, 90},
		{94, 100, 90},
		{100, 81, 82},
		{83, 65, 85},
		{78, 87, 65},
		{85, 75, 83},
		{91, 94, 100},
		{76, 72, 84},
		{87, 93, 73}
	} };
	GradeBook gd(std);
	gd.print();

	return 0;
}
