#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numer;
	int m_denom;
public:
	Fraction(int, int);
	Fraction();
	Fraction(const Fraction&);
	~Fraction();
	int getNumer() const;
	int getDenom() const;
	void print() const;
	void setNumer(int);
	void setDenom(int);
private:
	void normalize();
	int gcd(int, int);
};

Fraction::Fraction(int numer, int denom)
	:m_numer(numer), m_denom(denom)
{
	normalize();
}

Fraction::Fraction()
	: m_numer(0), m_denom(1)
{}

Fraction::Fraction(const Fraction& f)
	:m_numer(f.m_numer), m_denom(f.m_denom)
{}

Fraction::~Fraction()
{}

int Fraction::getNumer() const
{
	return m_numer;
}

int Fraction::getDenom() const
{
	return m_denom;
}

void Fraction::print() const
{
	cout << m_numer << " / " << m_denom << endl;
}

void Fraction::setNumer(int numer)
{
	m_numer = numer;
	normalize();
}

void Fraction::setDenom(int denom)
{
	m_denom = denom;
	normalize();
}

void Fraction::normalize()
{
	if (m_denom < 0)
	{
		m_numer = -m_numer;
		m_denom = -m_denom;
	}
	int divisor = gcd(m_numer, m_denom);
	m_numer /= divisor;
	m_denom /= divisor;
}

int Fraction::gcd(int a, int b)
{
	int myGcd = 1;
	for (int i = 1; i <= a && i <= b; ++i)
	{
		if (a % i == 0 && b % i == 0)
			myGcd = i;
	}
	return myGcd;
}

int main()
{
	Fraction f1;
	Fraction f2(14, 21);
	Fraction f3(11, -8);
	Fraction f4(f3);
	cout << "print out 4 fractions" << endl;
	f1.print();
	f2.print();
	f3.print();
	f4.print();
	cout << endl;
	cout << "after changing fraction 1 and 2 " << endl;
	f1.setNumer(4);
	f2.setDenom(-5);
	f1.print();
	f2.print();
	cout << endl;
	cout << "check numerator and denominator with accessor" << endl;
	cout << "numerator of fraction1: " << f1.getNumer() << endl;
	cout << "denominator of fraction2: " << f2.getDenom() << endl;

	return 0;
}
