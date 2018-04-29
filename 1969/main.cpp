#include <iostream>

using namespace std;

int main()
{
	int n, i;
	while (cin >> n)
	{
		int cn = n;
		int layer = 1;
		for (i = 1; i < n; ++i)
		{
			if (cn > i)
			{
				cn -= i;
				layer++;
			}
			else
			{
				break;
			}
		}
		
		if (layer % 2 == 0)
		{
			cn = layer + 1 - cn;
		}
		cout << "TERM " << n << " IS " << layer + 1 - cn << "/" << cn << endl;
	}
	return 0;
}