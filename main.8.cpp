#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source); // 받은 문자열이 없는 경우 오류 창 띄움
		
		m_length = strlen(source) + 1; 
		// 문자열의 마지막을 알리는 null character를 추가하기 위해 한자리 추가
		m_data = new char[m_length];

		for (int i = 0; i < m_length; i++)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	MyString(const MyString& source)
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;
	}

	MyString& operator = (const MyString& source)
	{
		cout << "Assignment operator " << endl;

		if (this == &source) // prevent self-assignment
			return *this;

		delete[] m_data; // 기존에 저장된 data를 삭제

		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length]; 
			// deep copy 
			// 메로리를 새로 할당 받아서 주소가 복사되는 것을 피함

			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = nullptr;

		return *this;
	}
	~MyString()
	{
		delete[] m_data;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;
	
	{
		MyString copy = hello;
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}

	cout << hello.getString() << endl;

	system("pause");
	return 0;
}