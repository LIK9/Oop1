#include <iostream>
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

//double midAvg(const Student* std, int size)	
//{	
//	int sum = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		sum +=  (* (std + i)).getMid();
//	}
//	return sum / static_cast<double>(size);
//}
//
//double finalAvg(const Student* std, int size)
//{
//	int sum = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		sum += (*(std + i)).getFinal();
//	}
//	return sum / static_cast<double>(size);
//}

int* getMid(const Student* std, const int size)
{
	int* mid = new int[size];
	for (int i = 0; i < size; ++i)
		mid[i] = std[i].getMid();
	return mid;
}

int* getFinal(const Student* std, const int size)
{
	int* fin = new int[size];
	for (int i = 0; i < size; ++i)
		fin[i] = std[i].getFinal();
	return fin;
}

double getAvg(const int* tst, const int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += tst[i];
	return static_cast<double>(sum) / size;

}

void print(const Student* std, int size)
{
	cout << setw(25) << "midterm final" << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << "Student ";
		if (i < 10)
			cout << "0" << i + 1 << ": ";
		else
			cout << i + 1 << ": ";
		cout << setw(5) << (*(std + i)).getMid() << setw(5) << (*(std + i)).getFinal() << endl;
	}
	cout << setw(12) << "Average: " << setw(5) << fixed << setprecision(1) << getAvg(getMid(std, size), size) << setw(5) << getAvg(getFinal(std, size), size);
}

int main()
{	
	int size;
	do
	{
		cout << "Enter the number of students: ";
		cin >> size;
	} while (size <= 0 || size > 99);

	Student* std = new Student[size];

	print(std, size);

	delete[] std;

	return 0;
}
