//////////////////////////////////////////////////////////////////////////////
// Goods.h
// заголовочний файл Ц визначенн€ класу
#pragma once
#include <iostream>
#include "Money.h"
#include "Object.h"
using namespace std;
class Goods :
	public Money

{
	string name;
	int price, quantity, no, date;

	Money money;
public:
	string GetName() const { return name; };
	int GetDate() const { return date; };
	int GetPrice() const { return price; };
	int GetQuantity() const { return quantity; };
	int GetNo() const { return no; };
	void SetName(string value) { name = value; };
	void SetDate(int value) { date = value; };
	void SetPrice(int value) { price = value; };
	void SetQuantity(int value) { quantity = value; };
	void SetNo(int value) { no = value; }
	void SetMoney(Money value)
	{
		money.SetHr(value.GetHr());
		money.SetKop(value.GetKop());
	}

	Goods();
	Goods(double, double, string, int, int, int, int);
	Goods(const Goods&);
	Goods& operator = (const Goods& s);

	friend Money operator +(const Money& that, const Money& other);
	friend Money operator -(const Money& that, const Money& other);
	friend double operator /(const Money& that, const Money& other);
	friend Money operator /(const Money& that, double division);
	friend Money operator *(const Money& that, double mult);

	Goods& operator<<(double newPrice);
	Goods& operator+(double amount);
	Goods& operator-(double amount);
	Goods& operator+(const Goods& money);

	Goods& operator ++();
	Goods& operator --();
	Goods operator ++(int);
	Goods operator --(int);

	operator string () const;
	friend ostream& operator <<(ostream& out, const Goods& x);
	friend istream& operator >>(istream& in, Goods& x);
	~Goods() { };
};
