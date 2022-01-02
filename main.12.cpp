#include <iostream>
#include <string>

using namespace std;

class IErrorLog // �������̽� Ŭ����
{
public:
	virtual bool reportError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog 
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	bool reportError(const char* errorMessage) override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(IErrorLog& log)
{
	log.reportError("Runtime error!!");
}

int main()
{
	FileErrorLog file_log;
	ConsoleErrorLog console_log;

	doSomething(file_log);      // �Ű������� Ÿ���� IErrorLog������ 
	doSomething(console_log);   // IErroLog�� ��ӹ޴� FileErrorLog, ConsoleErrorLog�� ��� ����

	system("pause");
	return 0;
}