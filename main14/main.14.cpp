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

// 템플릿
// type만 다른 반복되는 함수에 대해 템플릿으로 지정
// 템플릿 함수에 클래스를 매개변수로 줄 경우
// 오류가 많이 생길 수 있음