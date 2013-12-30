#include <iostream>
using namespace std;

int count(string a)
{
	int check = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		int v = (int)a[i];
		check |= 1 << v;
	}
	return check;
}

bool anagram(string a, string b)
{
	if (count(a) == count(b)) return true;
	return false;
}

int main()
{
	string a = "abchd", b = "bcda";
	cout<<anagram(a, b)<<endl;
}
