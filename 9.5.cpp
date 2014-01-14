#include <iostream>
#include <string>
using namespace std;

int find(string str[], int m, int n, string goal)
{
	while (m<n)
	{
		int mid = (m + n) >> 1;
		while (str[mid] == "" && mid <= n) mid++;
		if (str[mid] == goal) return mid;
		if (goal > str[mid]) m = mid;
		else n = mid;
	}

}

int main()
{
	string str[] = { "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };
	cout << find(str, 0, 12, "car") << endl;
}
