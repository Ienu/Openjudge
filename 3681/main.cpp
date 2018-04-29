#include <iostream>

using namespace std;

int main()
{
	int a, temp, i, sum = 0;
	cin >> a;
	for (i = 1; i < 6; ++i)
	{
		cin >> temp;
		if (temp < a)
		{
			sum += temp;
		}
	}
	cout << sum << endl;
	return 0;
}