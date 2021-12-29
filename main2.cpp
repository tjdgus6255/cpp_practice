#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	const int& getDay()
	{
		return m_day;
	}

	void copyFrom(const Date& original) // 같은 클래스 내의 인스턴스 끼리는 접근 가능
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
};

int main(int argc, char *argv[])
{	
	Date today;
	today.setDate(8, 4, 2025);
	today.setMonth(10);

	Date copy;
	copy.copyFrom(today);

	system("pause");
	return 0;
}
