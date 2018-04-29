#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string mul(string str, int s)
{
	string res(str.length(), '0');
	int i, v, up = 0;
	for (i = str.length() - 1; i >= 0; --i)
	{
		v = up + (str[i] - '0') * s;
		res[i] += v % 10;
		up = v / 10;
	}
	if (up > 0)
	{
		char head[8];
		sprintf(head, "%d", up);
		return string(head) + res;
	}
	return res;
}

int main()
{
	string str;
	int n, i;
	while (cin >> str >> n)
	{
		int scale = str.find_first_of('.'), len = str.length();
		if (scale == -1)
		{
			scale = len - 1;
		}
		else
		{
			str.erase(str.begin() + scale);
		}
		str = str.substr(str.find_first_not_of('0'));
		string result = str;
		int ss = stoi(str);
		for (i = 1; i < n; ++i)
		{
			result = mul(result, ss);
		}
		int step = (len - 1 - scale) * n;
		if (step > result.length())
		{
			string zero(step - result.length(), '0');
			result = "." + zero + result;
		}
		else
		{
			result.insert(result.end() - step, '.');
		}
		result = result.substr(0, result.find_last_not_of('0') + 1);
		if (result.back() == '.')
		{
			result.erase(result.end() - 1);
		}
		cout << result << endl;
	}
	return 0;
}