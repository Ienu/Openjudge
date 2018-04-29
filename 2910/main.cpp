#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int i, j;
	for (i = 0; i < str.length(); ++i)
	{
		string res;
		if (str[i] >= '1' && str[i] <= '9')
		{
			res.push_back(str[i]);
			for (j = i + 1; j < str.length(); ++j)
			{
				if (str[j] >= '0' && str[j] <= '9')
				{
					res.push_back(str[j]);
				}
				else
				{	
					break;
				}
			}
			i = j;
			cout << stoi(res) << endl;
		}
	}
	return 0;
}