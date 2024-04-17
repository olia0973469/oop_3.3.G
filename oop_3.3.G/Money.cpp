//////////////////////////////////////////////////////////////////////////////
// Money.cpp
// פאיכ נואכ³חאצ³¿ – נואכ³חאצ³ÿ לועמה³ג ךכאסף

#include "Money.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Money::Money()
	: hr(0), kop(0)
{}

Money::Money(const long hr)
	: hr(hr), kop(0)
{}

Money::Money(const int kop)
	: hr(0), kop(kop)
{}

Money::Money(const long hr, const int kop)
	: hr(hr), kop(kop)
{}

Money::Money(const Money& m)
	: hr(m.hr), kop(m.kop)
{}

Money& Money::operator = (const Money& m)
{
	this->hr = m.hr;
	this->kop = m.kop;
	return *this;
}

Money operator +(const Money& that, const Money& other)
{
	Money result;
	result.SetHr(that.hr + other.hr);
	result.SetKop(that.kop + other.kop);
	return result;
}

Money operator -(const Money& that, const Money& other)
{
	Money result;
	result.SetHr(that.hr - other.hr);
	result.SetKop(that.kop - other.kop);

	if (result.kop >= 100)
	{
		result.hr -= result.kop / 100;
		result.kop = 100;
	}

	return result;
}

double operator /(const Money& that, const Money& other)
{
	if (other.hr == 0 || other.kop == 0)
	{
		cout << "Error: Division by zero" << endl;
		return 0.0;
	}

	double totalThat = that.hr - (static_cast<double>(that.kop) / 100);
	double totalOther = other.hr - (static_cast<double>(other.kop) / 100);

	return totalThat / totalOther;
}

Money operator /(const Money& that, double division)
{
	if (division == 0.0)
	{
		cerr << "Error.\n";
		exit(1);
	}

	Money result;
	result.hr = that.hr / division;
	result.kop = that.kop / division;

	return result;
}

Money operator *(const Money& that, double mult)
{
	Money result;
	result.SetHr(that.hr * mult);
	result.SetKop(that.kop * mult);
	return result;
}

Money operator!=(const Money& that, const Money& other)
{
	Money result;
	result.hr = (that.hr != other.hr) ? that.hr : 0;
	result.kop = (that.kop != other.kop) ? that.kop : 0;
	return result;
}

Money operator<=(const Money& that, const Money& other)
{
	Money result;
	double totalThis = that.hr + (static_cast<double>(that.kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis < totalOther)
	{
		result.hr = that.hr;
		result.kop = that.kop;
	}
	return result;
}

Money operator>(const Money& that, const Money& other)
{
	Money result;

	double totalThis = that.hr + (static_cast<double>(that.kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis > totalOther)
	{
		result.hr = that.hr;
		result.kop = other.kop;
	}

	return result;
}

Money operator>=(const Money& that, const Money& other)
{
	Money result;
	double totalThis = that.hr + (static_cast<double>(that.kop) / 100);
	double totalOther = other.hr + (static_cast<double>(other.kop) / 100);

	if (totalThis >= totalOther)
	{
		result = that;
	}
	return result;
}

Money::operator string() const
{
	stringstream ss;
	ss << "(" << hr << " UAH , Kop " << kop << ")" << endl;
	return ss.str();
}

Money& Money::operator ++()
{
	++hr;
	return *this;
}

Money& Money::operator --()
{
	--hr;
	return *this;
}

Money Money::operator ++(int)
{
	Money tmp = *this;
	++kop;
	return tmp;
}

Money Money::operator --(int)
{
	Money tmp = *this;
	--kop;
	return tmp;
}

ostream& operator <<(ostream& out, const Money& x)
{
	out << string(x);
	return out;
}

istream& operator >>(istream& in, Money& x)
{
	cout << " Hryvni: "; in >> x.hr;
	cout << " Kopijky: "; in >> x.kop;
	return in;
}
