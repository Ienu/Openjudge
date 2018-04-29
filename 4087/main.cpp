#include <iostream>
#include <algorithm>

using namespace std;

void ssort(long* p1, long* p2)
{
	long temp = *(p2 - 1);
	p2 -= 2;
	while (p2 >= p1)
	{
		if (temp > *p2)
		{
			*(p2 + 1) = temp;
			return;
		}
		else
		{
			*(p2 + 1) = *p2;
			p2--;
		}
	}
	*p1 = temp;
}

int main()
{
	int n, k, i;
	cin >> n >> k;
	long *data = new long[k];
	for (i = 0; i < k; ++i)
	{
		cin >> data[i];
	}
	sort(data, data + k);
	long temp;
	int mTime = 0;
	for (; i < n; ++i)
	{
		cin >> temp;
		if (temp < data[k - 1])
		{
			data[k - 1] = temp;
			ssort(data, data + k);
		}
	}
	cout << data[k - 1] << endl;
	delete[] data;
	return 0;
}