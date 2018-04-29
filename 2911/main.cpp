#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int m, i, j;
	cin >> m;
	vector<int> vs;
	for (i = 32; i < 100 && i * i < m; ++i)
	{
		for (j = 1; j < 9; ++j)
		{
			int A = 1111 * j + i * i;
			if (A < 10000)
			{
				int root = sqrt(double(A));
				if (root * root == A)
				{
					vs.push_back(A);
				}
			}
		}
	}
	sort(vs.begin(), vs.end());
	for (i = 0; i < vs.size(); ++i)
	{
		cout << vs[i] << endl;
	}
	return 0;
}