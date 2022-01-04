#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int> container;
	//list<int> container;
	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	//auto itr = li.begin();
	// list<int>::const_iterator itr;
	auto itr = min_element(container.begin(), container.end());
	cout << *itr << endl;

	itr = max_element(container.begin(), container.end());
	cout << *itr << endl;

	cout << endl;

	itr = find(container.begin(), container.end(), 3);
	container.insert(itr, 128);

	for (auto& e : container) cout << e << " ";
	cout << endl;

	sort(container.begin(), container.end());
	//container.sort();

	for (auto& e : container) cout << e << " ";
	cout << endl;

	reverse(container.begin(), container.end());
	//container.reverse();

	for (auto& e : container) cout << e << " ";
	cout << endl;

	return 0;
}

// list는 sort와 reverse를 내부에 가지고 있음
// 사용시 인스턴스.sort(); / 인스턴스.reverse();로 해야함