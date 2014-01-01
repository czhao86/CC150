#include <iostream>
using namespace std;

struct node
{
	int val, min;
};

class stack
{
	int top, size;
	node *p;
public:
	stack(int size = 30);
	~stack();
	int pop();
	void push(int num);
	void display();
	int min();
};

stack::stack(int size)
{
	top = -1;
	p = new node[30];
	size = 30;
}

stack::~stack()
{
	delete[] p;
}

int stack::pop()
{
	int x = p[top].val;
	top--;
	return x;
}

void stack::push(int num)
{
	p[top+1].val = num;
	top++;
	if (top == 0) p[top].min = num;
	else
	{
		if (p[top].val < p[top - 1].min) p[top].min = p[top].val;
		else p[top].min = p[top - 1].min;
	}
}

int stack::min()
{
	return p[top].min;
}

void stack::display()
{
	for (int i = 0; i < top + 1; ++i)
	{
		cout << p[i].val << ' ';
	}
}

void main()
{
	stack s;
	for (int i = 2; i < 10; ++i)
	{
		s.push(3 * i);
	}
	for (int i = 1; i < 10; ++i)
	{
		s.push(3 * i);
	}
	s.display();
	cout << endl;
	cout << s.min() << endl;
}
