#include <iostream>
using namespace std;

struct node
{
	int val, preInd;
};

class stack3
{
	int top[3], size;
	int current=0;
	node *p;
public:
	stack3(int size = 30);
	~stack3();
	int pop(int stackNo);
	void push(int stackNo, int num);
	void display(int stackNo);
};

stack3::stack3(int size)
{
	top[0] = top[1] = top[2] = -1;
	p = new node[30];
	size = 30;
}

stack3::~stack3()
{
	delete[] p;
}

int stack3::pop(int stackNo)
{
	return p[top[stackNo]].val;
	top[stackNo] = p[top[stackNo]].preInd;
}

void stack3::push(int stackNo, int num)
{
	p[current].val = num;
	p[current].preInd = top[stackNo];
	top[stackNo] = current;
	current++;
}

void stack3::display(int stackNo)
{
	for (int i = 0; i < 10;++i)
	{
		cout << p[top[stackNo]].val << ' ';
		top[stackNo] = p[top[stackNo]].preInd;
	}
}

void main()
{
	stack3 s;
	for (int i = 0; i < 10; ++i)
	{
		s.push(0, i);
		s.push(1, 2 * i);
	}
	cout << s.pop(1) << endl;
	cout << s.pop(0) << endl;
	s.display(0);
	cout << endl;
	s.display(1);
	cout << endl;
}
