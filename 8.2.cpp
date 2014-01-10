#include <iostream>
using namespace std;

int path(int a, int b)
{
	if (a == 0 || b==0) return 1;
	else return path(a - 1, b) + path(a, b - 1);
}

int main()
{
	int x, y;
	cin >> x;
	cin >> y;
	cout << path(x, y) << endl;
	return 0;	
}
