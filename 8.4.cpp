#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> allper(string a)
{
	vector<string> result;
	if (a == "")
	{
		result.push_back("");
		return result;
	}
	vector<string> prev = allper(a.substr(1));
	string left = a.substr(0, 1);
	for (int i = 0; i < prev.size(); ++i)
	{
		string op = prev[i];
		for (int j = 0; j < op.length()+1; ++j)
		{
			string temp = op;
			temp.insert(j, left);
			result.push_back(temp);
		}
	}
	return result;
}

int main()
{
	string aa = "abcde";
	vector<string> bb = allper(aa);
	for (int i = 0; i < bb.size(); ++i)
		cout << bb[i] << endl;
	return 0;
}
