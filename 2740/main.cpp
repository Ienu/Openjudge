#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double calArea(double x1, double y1, double x2, double y2)
{
	return fabs((x1 - x2) * (y1 - y2));
}
double calArea(double x, double y, double r)
{
	return r * r * 3.1415926;
}
double calArea(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	double b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	double c = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
int main()
{
	int n, i;
	double x1, y1, x2, y2, r, x3, y3, area;
	cin >> n;
	string str;
	for (i = 0; i < n; ++i)
	{
		cin >> str;
		if (str == "Rect")
		{
			cin >> x1 >> y1 >> x2 >> y2;
			area = calArea(x1, y1, x2, y2);
		}
		else if (str == "Circle")
		{
			cin >> x1 >> y1 >> r;
			area = calArea(x1, y1, r);
		}
		else
		{
			cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
			area = calArea(x1, y1, x2, y2, x3, y3);
		}
		cout << setprecision(5) << fixed << area << endl;
	}
	return 0;
}