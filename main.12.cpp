#include <iostream>
#include <string>

using namespace std;

class IErrorLog // 인터페이스 클래스
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

	doSomething(file_log);      // 매개변수의 타입이 IErrorLog이지만 
	doSomething(console_log);   // IErroLog를 상속받는 FileErrorLog, ConsoleErrorLog도 사용 가능

	system("pause");
	return 0;
}