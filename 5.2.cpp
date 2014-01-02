#include <iostream>
#include <string>
using namespace std;

void binary(string a)
{
	int pos=a.find('.', 0);
	int m=atoi(a.substr(0, pos).c_str());
	double n = atof(a.substr(pos,a.length()-pos).c_str());
	string mm="", nn="";
	while (m > 0)
	{
		if (m & 1) mm="1"+mm;
		else mm="0"+mm;
		m >>= 1;
	}
	while (n > 0)
	{
		if (2*n>=1) nn="1"+nn;
		else nn="0"+nn;
		n=n*2-1;
	}
	if (n != 0) cout << "ERROR" << endl;
	cout <<mm<<'.'<<nn<<endl;
}

int main()
{
	string a = "12.5";
	binary(a);
}
