#include <iostream>
using namespace std;

class stack3
{
	int top[3], size;
	int *p;
public:
	stack3(int size= 30);
	~stack3();
	int pop(int stackNo);
	void push(int stackNo, int num);
	void display(int stackNo);
};

stack3::stack3(int size)
{
	top[0]=top[1]=top[2] = -1;
	p = new int[30];
	size = 30;
}

stack3::~stack3()
{
	delete[] p;
}

int stack3::pop(int stackNo)
{
	int x = p[10*stackNo+top[stackNo]];
	top[stackNo]--;
	return x;
}

void stack3::push(int stackNo, int num)
{
	p[10*stackNo+top[stackNo]+1] = num;
	top[stackNo]++;
}

void stack3::display(int stackNo)
{
	for (int i = 10*stackNo; i < 10*stackNo+top[stackNo]+1; ++i)
	{
		cout << p[i] << ' ';
	}
}

void main()
{
	stack3 s;
	for (int i = 0; i < 10; ++i)
	{
		s.push(0, i);
		s.push(1, 2 * i);
		s.push(2, 3 * i);
	}
	s.display(0);
	cout << endl;
	s.display(1);
	cout << endl;
	s.display(2);
	cout << endl;
	cout<<s.pop(0)<<endl;
	cout<<s.pop(0)<<endl;
}
