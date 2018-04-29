#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
	char num[11];
	int mon;
	int day;
	double hash;
};

bool compare(student s1, student s2)
{
	return s1.hash < s2.hash;
}

int main()
{
	int n, i, j;
	cin >> n;
	vector<student> vs;
	for (i = 0; i < n; ++i)
	{
		student stu;
		cin >> stu.num >> stu.mon >> stu.day;
		stu.hash = stu.mon * 100 + stu.day;
		vs.push_back(stu);
	}
	sort(vs.begin(), vs.end(), compare);
	for (i = 0; i < n - 1; ++i)
	{
		if (vs[i].hash == vs[i + 1].hash)
		{
			cout << vs[i].mon << " " << vs[i].day;
			for (j = i; j < n; ++j)
			{
				if (vs[j].hash == vs[i].hash)
				{
					cout << " " << vs[j].num;
				}
				else
				{
					break;
				}
			}
			i = j - 1;
			cout << endl;
		}
	}
	return 0;
}