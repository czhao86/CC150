#include <iostream>
#include <stack>
using namespace std;

class stackSort
{
	stack<int> s1, s2;
public:
	void push(int num)
	{
		s1.push(num);
	}
	void sort()
	{	
		s2.push(s1.top());
		s1.pop();
		while (!s1.empty())
		{
			if (s1.top() > s2.top())
			{	s2.push(s1.top());
				s1.pop();
			}
			else
			{	int min = s1.top();
				s1.pop();
				while (!s2.empty() && min < s2.top())
				{
					s1.push(s2.top());
					s2.pop();
				}
				s2.push(min);
			}
		}
		while (!s2.empty())
		{
			cout <<s2.top() << ' ';
			s2.pop();
		}
	}
};

int main()
{
	int i;
	stackSort s;
	for (i = 20; i > 10; --i)
	{
		s.push(i);
	}
	for (i = 10; i < 20; ++i)
	{
		s.push(i);
	}
	s.sort();
}
