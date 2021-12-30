#include <iostream>

using namespace std;


class A; // forward declation

class B 
{
private:
	int m_value = 2;
public:
	void doSomething(A& a); // ���� �������� A Ŭ������ �����ϴ� ���� �˰� ����
};

class A
{
private:
	int m_value = 1;
public:
	friend void B::doSomething(A& a); // B Ŭ������ doSomething ��� �Լ� ����
};


void B::doSomething(A& a) 
{
	cout << a.m_value << endl; // A Ŭ������ m_value ��� ������ �˰� ����
}

int main()
{
	A a;
	B b;
	b.doSomething(a);
	system("pause");
	return 0;
}

// ������ �߿���