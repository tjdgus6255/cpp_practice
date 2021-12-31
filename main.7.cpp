#include <iostream>
#include <cassert>
using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0)
	{
		m_cents = cents;
	}

	int getCents() { return m_cents;}
	void setCents(int cents) { m_cents = cents; }

	operator int()
	{
		cout << "cast here" << endl;

		return m_cents;
	}
};

class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int& input) : m_dollars(input) {}

	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Dollar dol(2); 
	// 멤버 변수 m_dollars가 2인 dol 인스턴스 생성

	Cents cents = dol; 
	
	// Cents 클래스로 형변환 & 형변환 operator 실행 

	printInt(cents);

	system("pause");
	return 0;
}