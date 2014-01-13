#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> allsubsets(int a[], int n)
{
	vector<vector<int>> subsets;
	int max = 1 << n;
	for (int i = 0; i < max; ++i)
	{
		vector<int> subset;
		int j = i;
		int ind = 0;
		while (j>0)
		{
			if (j&1)
				subset.push_back(a[ind]);
			j >>= 1;
			ind++;	
		}
		subsets.push_back(subset);
	}
	return subsets;
}

vector<vector<int>> allsubsets1(int a[], int ind, int n)
{
	vector<vector<int>> subsets;	
	if (ind == n)
	{
		vector<int> subset;
		subsets.push_back(subset);
	}
	else
	{
		vector<vector<int>> presubsets=allsubsets1(a, ind + 1, n);
		int tar = a[ind];
		for (int i = 0; i < presubsets.size(); ++i)
		{
			vector<int> subsett=presubsets[i];
			subsets.push_back(subsett);
			subsett.push_back(tar);
			subsets.push_back(subsett);
		}
	}
	return subsets;
}

void printsubsets(vector<vector<int>> subsets)
{
	for (int i = 0; i < subsets.size(); ++i)
	{
		vector<int> subset = subsets[i];
		for (int j = 0; j < subset.size(); ++j)
		{
			cout << subset[j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int a[4] = { 1, 5, 2 ,6 };
	//vector<vector<int>> as = allsubsets(a, 4);
	//printsubsets(as);
	vector<vector<int>> as1 = allsubsets1(a, 0, 4);
	printsubsets(as1);
	return 0;
}
