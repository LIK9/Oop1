#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
private:
	string m_name;
	int m_score;
	static int s_count;
public:
	Student(string name, int score);
	static int getCount();
	string getName() const;
	int getScore() const;
	Student();
	void setName(string name);
	void setScore(int score);
};

Student::Student(string name, int score)
	: m_name(name), m_score(score)
{
	++s_count;
}

int Student::getCount()
{
	return s_count;
}

string Student::getName() const
{
	return m_name;
}

int Student::getScore() const
{
	return m_score;
}

Student::Student()
	:m_name("noname"), m_score(0)
{}

void Student::setName(string name)
{
	m_name = name;
}

void Student::setScore(int score)
{
	m_score = score;
}

int Student::s_count = 0;

void findMinMaxStudent(const vector<Student>& student, Student minMax[])
{
	minMax[0].setScore(100);
	minMax[1].setScore(0);
	for (int i = 0; i < student.size(); ++i)
	{
		if (minMax[0].getScore() > student[i].getScore())
		{
			/*minMax[0].setScore(student[i].getScore());
			minMax[0].setName(student[i].getName());*/
			minMax[0] = student[i];
		}
		if (minMax[1].getScore() < student[i].getScore())
		{
			/*minMax[1].setScore(student[i].getScore());
			minMax[1].setName(student[i].getName());*/
			minMax[1] = student[i];
		}
	}
}

int main()
{
	vector<Student> student{};
	cout << "Enter the name and score of student." << endl;
	cout << "(EOF to quit) ? ";
	string name;
	int score;
	while (cin >> name >> score)
	{
		student.push_back(Student(name, score));
		cout << "(EOF to quit) ? ";
	}
	cout << "The number of students: " << Student::getCount() << endl;
	Student minMax[2];

	findMinMaxStudent(student, minMax);

	cout << "Mininum and Maximun scores" << endl;
	cout << minMax[0].getName() << " " << minMax[0].getScore() << " " << minMax[1].getName() << " " << minMax[1].getScore() << endl;

	return 0;
}
