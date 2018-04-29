#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

class pos
{
public:
	int x;
	int y;

public:
	pos() {}
	pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	pos operator-(pos a)
	{
		return pos(x - a.x, y - a.y);
	}
};

inline int cross(pos a, pos b)
{
	return a.x * b.y - a.y * b.x;
}

int main()
{
	int N, i, j;
	cin >> N;
	pos ps;
	vector<pos> convex;
	for (i = 0; i < N; ++i)
	{
		cin >> ps.x >> ps.y;
		if (i < 2)
		{
			convex.push_back(ps);
		}
		if (i == 2)
		{
			if (cross(convex[0] - ps, convex[1] - ps) > 0)
			{
				convex.insert(convex.begin() + 1, ps);
			}
			else
			{
				convex.push_back(ps);
			}
		}
		else
		{
			vector<int> outpos;
			for (j = 0; j < convex.size() - 1; ++j)
			{
				if (cross(convex[j] - ps, convex[j + 1] - ps) > 0)
				{
					outpos.push_back(j);
				}
			}
			if (cross(convex.back() - ps, convex.front() - ps) > 0)
			{
				outpos.push_back(j);
			}

			if (outpos.size() == 0)
			{
				continue;
			}
			else
			{
				if (outpos.size() > 1)
				{
					if (outpos.front() != 0 || outpos.back() != convex.size() - 1)
					{
						convex.insert(convex.begin() + outpos.front() + 1, ps);
						convex.erase(convex.begin() + outpos.front() + 2, convex.begin() + outpos.back() + 2);

					}
					else
					{
						for (j = 0; j < outpos.size() - 1; ++j)
						{
							if (outpos[j + 1] - 1 != outpos[j])
							{
								break;
							}
						}
						if (outpos[j + 1] + 1 <= convex.size())
						{
							convex.erase(convex.begin() + outpos[j + 1] + 1, convex.end());
						}
						convex.insert(convex.begin() + outpos[j + 1] + 1, ps);
						convex.erase(convex.begin() + outpos.front(), convex.begin() + outpos[j] + 1);
					}
				}
				else
				{
					convex.insert(convex.begin() + outpos[0] + 1, ps);
				}
			}
		}
	}

	float len = 0;
	for (i = 0; i < convex.size() - 1; ++i)
	{
		len += sqrt(pow(float(convex[i].x - convex[i + 1].x), 2)
			+ pow(float(convex[i].y - convex[i + 1].y), 2));
	}
	len += sqrt(pow(float(convex.front().x - convex.back().x), 2)
		+ pow(float(convex.front().y - convex.back().y), 2));
	cout << setiosflags(ios::fixed) << setprecision(2) << len << endl;

	return 0;
}