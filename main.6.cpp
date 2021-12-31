#include <iostream>

using namespace std;

class Digit
{
private:
	int m_digit;
public:
	Digit(int digit = 0) : m_digit(digit) {}

	//prefix
	Digit& operator ++ ()
	{
		++m_digit;
		return *this;
	}

	Digit& operator -- ()
	{
		--m_digit;
		return *this;
	}

	//postfix
	Digit operator ++ (int)
	{
		Digit temp(m_digit); 
		++(*this);
		return temp; 
		// temp 반환 이유 : (*this)++를 해주고 반환을 할 경우 
		// 이미 증감된 값을 반환하는 것이 되므로 
	}

	Digit operator -- (int)
	{
		Digit temp(m_digit);
		--(*this);
		return temp;
	}

	friend ostream& operator << (ostream& out, const Digit& d)
	{
		out << d.m_digit;
		return out;
	}
};

int main()
{
	Digit d(5);

	cout << ++d << endl;
	cout << d << endl;

	cout << d++ << endl;
	cout << d << endl;
	system("pause");
	return 0;
}