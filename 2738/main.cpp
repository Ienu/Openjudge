#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string str1, string str2)
{
	int len1 = str1.length(), len2 = str2.length();
	if (len1 > len2)
	{
		str2 = string(len1 - len2, '0') + str2;
	}
	else if (len2 > len1)
	{
		str1 = string(len2 - len1, '0') + str1;
	}
	string res(str1.length(), '0');
	int i, up = 0;
	for (i = str1.length() - 1; i >= 0; --i)
	{
		int v = up + str1[i] - '0' + str2[i] - '0';
		res[i] += v % 10;
		up = v / 10;
	}
	if (up > 0)
	{
		res = string(1, up + '0') + res;
	}
	return res;
}

int main()
{
	string str1, str2, s1i, s2i, s1d, s2d;
	cin >> str1 >> str2;
	int pos = str1.find('.');
	if (pos == -1)
	{
		s1i = str1;
		s1d = "";
	}
	else
	{
		s1i = str1.substr(0, pos);
		s1d = str1.substr(pos + 1);
	}
	if (s1d == "")
	{
		s1d = "0";
	}
	pos = str2.find('.');
	if (pos == -1)
	{
		s2i = str2;
		s2d = "";
	}
	else
	{
		s2i = str2.substr(0, pos);
		s2d = str2.substr(pos + 1);
	}
	if (s2d == "")
	{
		s2d = "0";
	}
	int len1 = s1d.length(), len2 = s2d.length(), maxlen = len1;
	if (len1 > len2)
	{
		s2d += string(len1 - len2, '0');
	}
	else if (len2 > len1)
	{
		s1d += string(len2 - len1, '0');
		maxlen = len2;
	}
	string res = add(s1i + s1d, s2i + s2d);
	string r = res.substr(0, res.length() - maxlen) + "." 
		+ res.substr(res.length() - maxlen);
	reverse(r.begin(), r.end());
	pos = r.find_first_not_of('0');
	r = r.substr(pos);
	reverse(r.begin(), r.end());
	cout << r << endl;
	return 0;
}