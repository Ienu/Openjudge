#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	char cstr[10000];
	int i;
	while (cin.getline(cstr, 10000))
	{
		string str(cstr);
		int eIdx = 1;
		for (i = 0; i < str.length(); ++i)
		{
			string subs;
			bool bStr = false;
			while ((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z'))
			{
				
				if ((str[i] >= 'a' + eIdx)
					|| (str[i] >= 'A' + eIdx && str[i] <= 'Z'))
				{
					str[i] -= eIdx;
				}
				else
				{
					str[i] += 26 - eIdx;
				}
				subs.push_back(str[i++]);
				bStr = true;	
			}
			if (bStr)
			{
				reverse(subs.begin(), subs.end());
				i--;
				eIdx++;
				cout << subs;
			}
			else
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}