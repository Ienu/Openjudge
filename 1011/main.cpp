#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, i, j, len;
	while (cin >> n && n != 0)
	{
		vector<int> vstick;
		int sum = 0;
		for (i = 0; i < n; ++i)
		{
			cin >> len;
			sum += len;
			vstick.push_back(len);
		}
		sort(vstick.begin(), vstick.end());
		int maxlen = vstick.back();
		cout << "max len = " << maxlen << " sum = " << sum << endl;
		for (i = maxlen; i <= sum; ++i)
		{
			if (sum % i != 0)
			{
				continue;
			}
			for (j = n - 2; j >= 0; --j)
			{
				if (vstick[j] < maxlen)
				{
					if (vstick[j] + vstick[0] > i)
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}