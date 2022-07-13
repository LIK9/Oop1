#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student
{
private:
	int m_mid;
	int m_final;
public:
	Student();
	int getMid() const;
	int getFinal() const;
};

class WLclass
{
private:
	Student* m_std;
	std::string m_className;
	int m_stdNum;
public:
	WLclass();
	/*double midAvg() const;
	double finalAvg() const;*/
	int* getMid() const;
	int* getFinal() const;
	double getAvg(const int* tst) const;
	void print() const;
	~WLclass();
};

Student::Student()
{
	std::cout << "Enter midterm and final score: ";
	std::cin >> m_mid >> m_final;
}

int Student::getMid() const
{
	return m_mid;
}

int Student::getFinal() const
{
	return m_final;
}

WLclass::WLclass()
{
	cout << "Enter the class name and number of students: ";
	cin >> m_className >> m_stdNum;

	m_std = new Student[m_stdNum];
	cout << endl;
}

//double WLclass::midAvg() const
//{
//	int sum = 0;
//	for (int i = 0; i < m_stdNum; ++i)
//	{
//		sum += (*(m_std + i)).getMid();
//	}
//	return sum / static_cast<double>(m_stdNum);
//}
//
//double WLclass::finalAvg() const
//{
//	int sum = 0;
//	for (int i = 0; i < m_stdNum; ++i)
//	{
//		sum += (*(m_std + i)).getFinal();
//	}
//	return sum / static_cast<double>(m_stdNum);
//}

int* WLclass::getMid() const
{
	int* tst = new int[m_stdNum];
	for (int i = 0; i < m_stdNum; ++i)
		tst[i] = m_std[i].getMid();
	return tst;
}
int* WLclass::getFinal() const
{
	int* tst = new int[m_stdNum];
	for (int i = 0; i < m_stdNum; ++i)
		tst[i] = m_std[i].getFinal();
	return tst;
}
double WLclass::getAvg(const int* tst) const
{
	int sum = 0;
	for (int i = 0; i < m_stdNum; ++i)
		sum += tst[i];
	return static_cast<double>(sum) / m_stdNum;
}

void WLclass::print() const
{
	cout << "<" << m_className << " class>" << endl;
	cout << setw(25) << "midterm final" << endl;
	for (int i = 0; i < m_stdNum; ++i)
	{
		cout << "Student ";
		if (i < 10)
			cout << "0" << i + 1 << ": ";
		else
			cout << i + 1 << ": ";
		cout << setw(5) << (*(m_std + i)).getMid() << setw(5) << (*(m_std + i)).getFinal() << endl;
	}
	cout << setw(12) << "Average: " << setw(5) << fixed << setprecision(1) << getAvg(getMid()) << setw(5) << getAvg(getFinal()) << endl;
	cout << endl;
}

WLclass::~WLclass()
{
	delete[] m_std;
}

int main()
{
	int size;
	do
	{
		cout << "Enter the number of class: ";
		cin >> size;
	} while (size <= 0);

	WLclass* cls = new WLclass[size];

	for (int i = 0; i < size; ++i)
	{
		(cls + i)->print();
	}

	delete[] cls;

	return 0;
}
