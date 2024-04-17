//////////////////////////////////////////////////////////////////////////////
//Source.cpp

#include"Goods.h"
#include"Money.h"
#include<iostream>

using namespace std;

int main()
{
	Goods s;
	Money m1;
	Money m;
	Money m2(m);
	int d;
	cout << "s = "; cin >> s;
	cout << s << endl;

	cout << "m1 = "; cin >> m1;
	cout << "m: " << m1 << endl;
	cout << "m2 = "; cin >> m2;
	cout << "m2: " << m2 << endl;

	Money res, res2, res3, res4;
	res = m1 + m2;
	cout << "Add: " << res << endl;
	res = m1 - m2;
	cout << "Sub: " << res << endl;
	double res1 = m1 / m2;
	cout << "Divide: " << res1 << endl;
	res2 = m1 / 2;
	cout << "Divide fraction: " << res2 << endl;
	res4 = m1 * m2;
	cout << "Multiply: " << res4 << endl;

	cout << "Price:" << endl;
	Goods g0(45, 56, "rrrrrr", 1, 2, 3, 4);
	cout << g0 << endl;
	g0 << 9;
	cout << "Change Price:" << endl;
	cout << g0 << endl;

	cout << "count = " << Money::Count() << endl;
	cout << "count = " << Goods::Count() << endl;
	cout << "count = " << Object::Count() << endl;
	return 0;
}
