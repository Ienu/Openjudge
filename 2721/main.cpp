#include <iostream>

using namespace std;

int main()
{
	char str1[81], str2[81];
	cin.getline(str1, 81);
	cin.getline(str2, 81);
	int i;
	for (i = 0; i < 81; ++i)
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			str1[i] += 'a' - 'A';
		}
		if (str2[i] >= 'A' && str2[i] <= 'Z')
		{
			str2[i] += 'a' - 'A';
		}
		if (str1[i] > str2[i])
		{
			cout << ">" << endl;
			return 0;
		}
		if (str1[i] < str2[i])
		{
			cout << "<" << endl;
			return 0;
		}
		if (str1[i] == '\0' && str2[i] == '\0')
		{
			break;
		}
	}
	cout << "=" << endl;
	return 0;
}