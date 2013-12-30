#include <iostream>
using namespace std;

bool isSubstring(string a, string b)
{
	if (a.find(b) != string::npos) return true;
	return false;
}

bool isRotation(string a, string b)
{
	if (a.length() != b.length()) return false;
	return isSubstring(a + a, b);
}

int main()
{
	string a = "apple", b = "leapp";
	cout << isRotation(a,b)<< endl;
}
