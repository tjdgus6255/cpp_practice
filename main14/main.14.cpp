#include <iostream>
#include "Cents.h"

using namespace std;

template<typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(1, 2) << endl;
	cout << getMax(3.14, 2.45) << endl;
	cout << getMax('a', 'x') << endl;

	cout << getMax(Cents(5), Cents(9)) << endl;
	system("pause");
	return 0;
}

// ���ø�
// type�� �ٸ� �ݺ��Ǵ� �Լ��� ���� ���ø����� ����
// ���ø� �Լ��� Ŭ������ �Ű������� �� ���
// ������ ���� ���� �� ����