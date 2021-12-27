#include <iostream>

using namespace std;

void printArray(const int array[], const int length)
{
	for (int index = 0; index < length; ++index)
		cout << array[index] << " ";
	cout << endl;
}

void selectionSort(int array[], const int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		int benchmark = array[i];
		int iter = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (benchmark > array[j])
			{
				benchmark = array[j];
				iter = j;
			}
		}
		// swap function
		if (array[i] != array[iter])
		{
			int temp = array[i];
			array[i] = array[iter];
			array[iter] = temp;
		}
		printArray(array, length);
	}
}

int main()
{	
	const int length = 5;

	int array[length] = { 3, 5, 2, 1, 4 };

	printArray(array, length);
	selectionSort(array, length);
	system("pause");
	return 0;
}

/*
C++ ���� ��ٰ� �������� ������ ���� ��� ���� �غ���� �ϼż�
�ѹ� ����� ���ҽ��ϴ�. 
C++�� �ͼ����� �ʾ� ������� ���� �κ��� �ֳ׿�.
*/