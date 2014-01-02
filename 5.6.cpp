#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 12;
	cout << (((a & 0xAA) >> 1) | ((a & 0x55) << 1)) << endl;
}
