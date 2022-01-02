#include <iostream>

using namespace std;

class PoweredDevice
{
public:
	int m_i;

	PoweredDevice(int power)
	{
		cout << "PoweredDevice: " << power << "\n";
	}
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner: " << scanner << "\n";
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer: " << printer << "\n";
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power)
		: Scanner(scanner, power), Printer(printer, power), PoweredDevice(power)
	{

	}
};

int main()
{
	Copier cop(1, 2, 3);

	cout << &cop.Scanner::PoweredDevice::m_i << endl;
	cout << &cop.Printer::PoweredDevice::m_i << endl;

	system("pause");
	return 0;
}

// 다이아몬드 상속 정의
// 같은 클래스(상위 클래스)를 상속받는 두 클래스(중위 클래스)가 존재하고
// 두 클래스를 상속 받는 클래스(하위 클래스)가 있을 때
// 상위 클래스가 두번 호출되는 문제

// 상속을 받을 때 virtual 키워드 삽입
// 하위 클래스에서는 상위 클래스에 대한 생성자 호출을 해주어야 함