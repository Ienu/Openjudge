#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n, i, cent[10];
	double score[10], GPA = 0, sumc = 0;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> cent[i];
		sumc += cent[i];
	}
	for (i = 0; i < n; ++i)
	{
		cin >> score[i];
		if (score[i] >= 90)
		{
			score[i] = 4.0;
		}
		else if (score[i] >= 85)
		{
			score[i] = 3.7;
		}
		else if (score[i] >= 82)
		{
			score[i] = 3.3;
		}
		else if (score[i] >= 78)
		{
			score[i] = 3.0;
		}
		else if (score[i] >= 75)
		{
			score[i] = 2.7;
		}
		else if (score[i] >= 72)
		{
			score[i] = 2.3;
		}
		else if (score[i] >= 68)
		{
			score[i] = 2.0;
		}
		else if (score[i] >= 64)
		{
			score[i] = 1.5;
		}
		else if (score[i] >= 60)
		{
			score[i] = 1.0;
		}
		else
		{
			score[i] = 0;
		}
		GPA += score[i] * cent[i];
	}
	cout << setprecision(2) << fixed << GPA / sumc << endl;
	return 0;
}