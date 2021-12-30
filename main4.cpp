#include <iostream>

using namespace std;


class A; // forward declation

class B 
{
private:
	int m_value = 2;
public:
	void doSomething(A& a); // 전방 선언으로 A 클래스가 존재하는 것을 알고 있음
};

class A
{
private:
	int m_value = 1;
public:
	friend void B::doSomething(A& a); // B 클래스의 doSomething 멤버 함수 인지
};


void B::doSomething(A& a) 
{
	cout << a.m_value << endl; // A 클래스의 m_value 멤버 변수를 알고 있음
}

int main()
{
	A a;
	B b;
	b.doSomething(a);
	system("pause");
	return 0;
}

// 순서가 중요함