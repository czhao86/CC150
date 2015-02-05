#include <iostream>
#include <stack>
using namespace std;

class myQueue
{
	stack<int> s1;
	stack<int> s2;
public:
	myQueue(){}
	~myQueue(){}
	void qadd(int num)
	{
		s1.push(num);
	}
	int qtop()
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
			s2.push(s1.top());
			s1.pop();
			}
		}
		return s2.top();
	}
};

int main()
{
	myQueue s;
	for (int i = 0; i < 10; ++i)
	{
		s.qadd(i);
	}
	cout << s.qtop() << endl;
}
