#include <iostream>

using namespace std;

class Timer
{
private:
	int m_hour, m_min, m_sec;
public:
	Timer(int hour, int min, int sec);
	Timer(const Timer&) = delete;
	Timer();
	~Timer();
	void print() const;
	void tick();
private:
	void normalize();
};


Timer::Timer(int hour, int min, int sec)
	: m_hour(hour), m_min(min), m_sec(sec)
{
	normalize();
}

Timer::Timer()
	:m_hour(0), m_min(0), m_sec(0)
{}

Timer::~Timer()
{}

void Timer::print() const
{
	cout << m_hour << " : " << m_min << " : " << m_sec << endl;
}

void Timer::tick()
{
	++m_sec;
	normalize();
}

void Timer::normalize()
{
	if (m_hour < 0 || m_min < 0 || m_sec < 0)
		abort();
	if (m_sec >= 60)
	{
		int temp = m_sec / 60;
		m_min += temp;
		m_sec %= 60;
	}
	if (m_min >= 60)
	{
		int temp = m_min / 60;
		m_hour += temp;
		m_min %= 60;
	}
	if (m_hour >= 24)
		m_hour %= 24;
}


int main()
{
	Timer t(4, 5, 27);
	cout << "original time: ";
	t.print();

	for (int i = 0; i < 143500; ++i)
		t.tick();

	cout << "after 143500 seconds: ";
	t.print();

	return 0;
}
