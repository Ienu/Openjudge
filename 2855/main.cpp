#include <iostream>

using namespace std;

int main()
{
	double x, y;
	while (cin >> x >> y)
	{
		cout << ((x * x / 16 + y * y / 9 < 1) ? "yes" : "no") << endl;
	}
	return 0;
}