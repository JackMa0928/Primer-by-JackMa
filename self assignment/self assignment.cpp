#include <iostream>
#include <string>
using namespace std;
class HasPtr1
{
public:
	HasPtr1(const string &s = string()) :ps(new string(s)), i(0) 
	{
		cout << "HasPtr1���캯��" << endl;
	}
	HasPtr1(const HasPtr1 &p) :ps(new string(*p.ps)), i(p.i) 
	{
		cout << "HasPtr1�������캯��" << endl;
	}
	HasPtr1& operator=(const HasPtr1 &);
	~HasPtr1() 
	{ 
		delete ps;
		cout << "HasPtr1��������" << endl;
	}
private:
	string *ps;
	int i;
};

class HasPtr2
{
public:
	HasPtr2(const string &s = string()) :ps(new string(s)), i(0) 
	{
		cout << "HasPtr2���캯��" << endl;
	}
	HasPtr2(const HasPtr2 &p) :ps(new string(*p.ps)), i(p.i)
	{
		cout << "HasPtr2�������캯��" << endl;
	}
	HasPtr2& operator=(const HasPtr2 &);
	~HasPtr2() 
	{ 
		delete ps; 
		cout << "HasPtr2��������" << endl;
	}
private:
	string *ps;
	int i;
};

HasPtr1& HasPtr1::operator=(const HasPtr1 &rhs)
{
	auto newp = new string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	cout << "HasPtr1���������" << endl;
	return *this;
}

HasPtr2& HasPtr2::operator=(const HasPtr2 &rhs)
{
	delete ps;
	ps = new string(*(rhs.ps));
	i = rhs.i;
	cout << "HasPtr2���������" << endl;
	return *this;
}

int main()
{
	HasPtr1 Hp1_1("Hello");
	HasPtr1 Hp1_2("World");
	HasPtr2 Hp2_1("C++");
	HasPtr2 Hp2_2("Primer");
	Hp1_1 = Hp1_1;
	Hp1_1 = Hp1_2;
	//Hp2_1 = Hp2_1;
	Hp2_1 = Hp2_2;
	return 0;
}