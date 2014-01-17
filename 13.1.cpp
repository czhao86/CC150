#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printklines(ifstream &f, int n)
{
	string k[4];
	string temp;
	int lines = 0;
	while (getline(f, temp))
	{
		k[lines % 4] = temp;
		lines++;
	}
	int start, cnt;
	if (lines < 4)
	{
		start = 0;
		cnt = lines;
	}
	if (lines>4)
	{
		start = lines % 4;
		cnt = 4;
	}
	for (int i = 0; i < cnt; ++i)
	{
		cout << k[(start + i)%4] << endl;
	}
}

int main()
{
	ifstream fin("13.1.in");
	printklines(fin, 4);
	fin.close();
	return 0;
}
