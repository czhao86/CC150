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

vector<string> allper1(string a)
{
	vector<string> result;
	if (a == "")
	{
		result.push_back("");
		return result;
	}
	for (int i = 0; i < a.length(); ++i)
	{		
		string one = a.substr(i, 1);
		string aa = a;
		vector<string> rest = allper1(aa.erase(i, 1));
		for (int j = 0; j < rest.size(); ++j)
		{
			result.push_back(one + rest[j]);
		}
	}
	return result;
}

int main()
{
	string aa = "abcde";
	vector<string> bb = allper1(aa);
	for (int i = 0; i < bb.size(); ++i)
		cout << bb[i] << endl;
	return 0;
}
