#include <iostream>

using namespace std;

int main()
{
	int n, i;
	cin >> n;
	double *st = new double[n];
	st[0] = 1;
	for (i = 1; i < n; ++i)
	{
		st[i] = st[i - 1] * (i + 1);
		cout << st[i] << endl;
	}
	double sum = 0;
	for (i = n - 1; i >= 0; --i)
	{
		sum += 1.0 / st[i];
	}
	cout << sum << endl;
	return 0;
}