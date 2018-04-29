#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool igCompare(string str1, string str2)
{
	int i;
	for (i = 0; i < str1.length(); ++i)
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			str1[i] += 'a' - 'A';
		}
	}
	for (i = 0; i < str2.length(); ++i)
	{
		if (str2[i] >= 'A' && str2[i] <= 'Z')
		{
			str2[i] += 'a' - 'A';
		}
	}
	return str1 < str2;
}

int main()
{
	string type;
	cin >> type;
	int n, i, j;
	cin >> n;
	cin.ignore();
	char cstr[1000];
	vector<string> vs;
	for (i = 0; i < n; ++i)
	{
		cin.getline(cstr, 1000);
		string str = string(cstr);
		int p1 = str.find_first_not_of(' ');
		int p2 = str.find_last_not_of(' ');
		vs.push_back(str.substr(p1, p2 - p1 + 1));
	}
	if (type == "inc")
	{
		sort(vs.begin(), vs.end());
	}
	else if (type == "dec")
	{
		sort(vs.begin(), vs.end());
		reverse(vs.begin(), vs.end());
	}
	else if (type == "ncinc")
	{
		sort(vs.begin(), vs.end(), igCompare);
	}
	else
	{
		sort(vs.begin(), vs.end(), igCompare);
		reverse(vs.begin(), vs.end());
	}
	for (i = 0; i < n; ++i)
	{
		cout << vs[i] << endl;
	}
	return 0;
}