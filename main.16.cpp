#include <iostream>

using namespace std;

class Exception
{
public:
	void report()
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int m_data[5];

public:
	int& operator [] (const int& index)
	{
		//if (index < 0 || index >= 5) throw - 1;
		if (index < 0 || index >= 5) throw ArrayException();
		return m_data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int& x)
	{
		cerr << "Exception " << x << endl;
	}
	catch (ArrayException& e)
	{
		cout << "doSomething()" << endl;
		e.report();
		throw e;
	}
	catch (Exception& e)
	{
		cout << "doSomething()" << endl;
		e.report();
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (ArrayException& e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}

////////////////////////////////////////////////////////
// 예외 클래스와 상속
// Exception을 상속받는 ArrayException
// MyArray 클래스의 멤버 함수에서 ArrayException을 throw함
// doSomething()의 catch 구문에서 매개변수 타입이 ArrayException인 부분을 실행
// 오류 구문을 rethrow함
// main의 catch에서도 실행됨