#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void last()
{
	cout << "last " << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "End last " << endl;
}

void third()
{
	cout << "Third" << endl;

	last();

	cout << "End third " << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "Second caught double exception" << endl;
	}

	cout << "End second " << endl;
}

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first " << endl;
}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}
	catch (...) // catch-all handlers
	{
		cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main" << endl;

	system("pause");
	return 0;
}

////////////////////////////////////////////////
// first() -> second() -> third() -> last()
// last()에서 throw -1(integer)
// last()와 third()에는 예외처리 구문이 없으므로 second()로 넘어감
// second()의 catch는 매개변수로 double형을 받아야 하므로 first()로 넘어감
// first()에서 예외처리 실행 후 main에서 종료