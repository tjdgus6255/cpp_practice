#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Timer
{
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now();

public:
	void elapsed()
	{
		chrono::time_point<clock_t> end_time = clock_t::now();

		cout << chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	shuffle(begin(vec), end(vec), mersenne_engine);

	for (auto& e : vec) cout << e << " ";
	cout << endl;

	Timer timer;

	sort(begin(vec), end(vec));

	timer.elapsed();

	for (auto& e : vec) cout << e << " ";
	cout << endl;

	system("pause");
	return 0;
}
