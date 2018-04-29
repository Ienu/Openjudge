#include <iostream>
#include <string>

using namespace std;

class BigNum
{
private:
	string data;

private:
	string erZero(string str)
	{
		int pos = str.find_first_not_of('0');
		if (pos == -1)
		{
			return "0";
		}
		return str.substr(pos);
	}

public:
	BigNum() 
	{
		data = "0";
	}
	BigNum(char* cstr)
	{
		data = string(cstr);
	}
	BigNum(string str)
	{
		data = erZero(str);
	}
	BigNum operator*(int s)
	{
		if (s == 0)
		{
			return BigNum("0");
		}
		if (s == 1)
		{
			return *this;
		}
		string strR(data.length(), '0');
		int i, up = 0;
		for (i = data.length() - 1; i >= 0; --i)
		{
			int v = up + (data[i] - '0') * s;
			up = v / 10;
			strR[i] += v % 10;
		}
		if (up != 0)
		{
			return BigNum(to_string(up) + strR);
		}
		return BigNum(strR);
	}
	BigNum operator-(BigNum bn)
	{
		if (data == bn.data)
		{
			return BigNum("0");
		}
		if (bn.data == "0")
		{
			return *this;
		}
		string str1 = data;
		string str2 = bn.data;
		if (str1.length() - str2.length() == 1)
		{
			str2 = "0" + str2;
		}
		int i;
		string res(str1.length(), '0');
		for (i = str1.length() - 1; i >= 0; --i)
		{
			int v = str1[i] - str2[i];
			if (v < 0)
			{
				v += 10;
				str1[i - 1]--;
			}
			res[i] += v;
		}
		return BigNum(erZero(res));
	}
	bool operator<(BigNum bn)
	{
		if (data.length() < bn.data.length())
		{
			return true;
		}
		if (data.length() == bn.data.length())
		{
			return data < bn.data;
		}
		return false;
	}
	bool operator<=(BigNum bn)
	{
		return data == bn.data || (*this < bn);
	}
	bool operator==(BigNum bn)
	{
		return data == bn.data;
	}
	string get()
	{
		return data;
	}
	BigNum operator/(BigNum bn)
	{
		if (*this < bn || data == "0")
		{
			return BigNum("0");
		}
		if (data == bn.data)
		{
			return BigNum("1");
		}
		string str1 = data, str2 = bn.data;
		int i, len2 = str2.length();
		string head = str1.substr(0, len2 - 1);
		string rest = str1.substr(len2 - 1);
		string result;
		while (rest.length() > 0)
		{
			head += rest.substr(0, 1);
			rest = rest.substr(1);
			for (i = 9; i >= 0; --i)
			{
				BigNum mVal = bn * i;
				if (mVal <= BigNum(head))
				{
					BigNum diff = BigNum(head) - mVal;
					head = diff.get();
					break;
				}
			}
			result.push_back('0' + i);
		}
		return BigNum(erZero(result));
	}
};

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	BigNum bn1(str1), bn2(str2);
	BigNum res = bn1 / bn2;
	cout << res.get() << endl;
	return 0;
}