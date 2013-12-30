#include <iostream>
using namespace std;

string removeDuplicate(string a)
{
	int check = 0;
	string c = "";
	for (int i = 0; i < a.length(); ++i)
	{
		if ((check & 1 << (int)(a[i]))==0)
		{
			check |= 1 << (int)(a[i]);
			c += a[i];
		}
	}
	return c;
}

string removeDuplicate2(string a)
{
	string b = "";
	for (int i = 0; i < a.length(); ++i)
	{
		for (int j = i + 1; j < a.length(); ++j)
		{
			if (a[i] == a[j]) a[j] = '\0';
		}
		if (a[i] != '\0') b += a[i];
	}
	return b;
}

int main()
{
	string b="abcdabcdefghiefghixxx";
	string x = removeDuplicate2(b);
	for (int i = 0; i < x.length(); ++i)
	{
		cout << x[i];
	}
	cout << endl;
	return 0;
}
