//////////////////////////////////////////////////////////////////////////////
// Money.h
// заголовочний файл Ц визначенн€ класу
#pragma once

#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Money :
	public Object
{
	double hr;
	double kop;
public:
	double GetHr() const { return hr; }
	double GetKop() const { return kop; }
	void SetHr(double value) { this->hr = value; }
	void SetKop(double value) { this->kop = value; }

	Money();
	Money(const long hr);
	Money(const int kop);
	Money(const long hr, const int kop);
	Money(const Money& m);
	Money& operator =(const Money& r);

	friend Money operator +(const Money& that, const Money& other);
	friend Money operator -(const Money& that, const Money& other);
	friend double operator /(const Money& that, const Money& other);
	friend Money operator /(const Money& that, double division);
	friend Money operator *(const Money& that, double mult);

	friend Money operator!=(const Money& that, const Money& other);
	friend Money operator<=(const Money& that, const Money& other);
	friend Money operator>(const Money& that, const Money& other);
	friend Money operator>=(const Money& that, const Money& other);

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);

	operator string() const;
	friend ostream& operator <<(ostream&, const Money&);
	friend istream& operator >>(istream&, Money&);
};
