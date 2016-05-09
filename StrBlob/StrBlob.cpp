#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string>il);
	size_type size() const
	{
		return data->size();
	}
	bool empty()
	{
		return data->empty();
	}
	void push_back(const string&t)
	{
		data->push_back(t);
	}
	void pop_back();
	string &front();
	string &back();
private:
	shared_ptr<vector<string>>data;
	void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() :data(make_shared<vector<string>>())
{

}
StrBlob::StrBlob(initializer_list<string>il) : data(make_shared<vector<string>>(il))
{

}
void StrBlob::check(size_type i, const string &msg)const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}
string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back()
{
	check(0, "back_pop on empty StrBlob");
	data->pop_back();
}

int main()
{
	vector<string>vec1;
	StrBlob str1;
	vector<string>vec = { "Hello","World" };
	StrBlob str = { "C","+","+" };
	vec1 = vec;
	str1 = str;
	string temp = "Primer";
	vec1.push_back(temp);
	str1.push_back(temp);
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	while (!str.empty())
	{
		cout << str.back() << " ";
		str.pop_back();
	}
	return 0;
}