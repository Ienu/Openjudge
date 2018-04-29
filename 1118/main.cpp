#include <iostream>
#include <vector>

using namespace std;

struct line
{
	double x;
	double y;
};
int main()
{
	int N, i, j, k;
	while (cin >> N && N != 0)
	{
		vector<line> vlpt;
		for (i = 0; i < N; ++i)
		{
			line li;
			cin >> li.x >> li.y;
			vlpt.push_back(li);
		}
		int maxC = 1;
		for (i = 0; i < N; ++i)
		{
			vector<line> vl;
			for (j = i + 1; j < N; ++j)
			{
				line ll;
				ll.x = vlpt[i].x - vlpt[j].x;
				ll.y = vlpt[i].y - vlpt[j].y;
				vl.push_back(ll);
			}
			for (j = 0; j < vl.size(); ++j)
			{
				int sum = 2;
				for (k = j + 1; k < vl.size(); ++k)
				{
					if (vl[j].x * vl[k].y
						- vl[k].x * vl[j].y == 0)
					{
						sum++;
					}
				}
				if (maxC < sum)
				{
					maxC = sum;
				}
			}
		}
		cout << maxC << endl;
	}
	return 0;
}