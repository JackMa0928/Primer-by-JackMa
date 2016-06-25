#include <iostream>
using namespace std;

class Quote
{
public:
	virtual double price() const
	{
		double price = 5.0;
		return price;
	}
};

class Quote_bulk :public Quote
{
public:
	virtual double price() const override
	{
		double bulk_price = 10.0;
		return bulk_price;
	}
};

double print_total(ostream &os, const Quote &item)
{
	double ret = item.price();
	os << "price:" << ret << endl;
	return ret;
}

int main()
{
	const Quote basic;
	const Quote_bulk bulk;
	print_total(cout, basic);
	print_total(cout, bulk);
	return 0;
}
