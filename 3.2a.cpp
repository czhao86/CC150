#include <iostream>
using namespace std;

class stack
{
	int top, size;
	int *p;
public:
	stack(int size = 30);
	~stack();
	int pop();
	void push(int num);
	void display();
	bool empty();
};

stack::stack(int size)
{
	top = -1;
	p = new int[30];
	size = 30;
}

stack::~stack()
{
	delete[] p;
}

int stack::pop()
{
	int x = p[top];
	return x;
}

void stack::push(int num)
{
	p[top+1] = num;
	top++;
}

void stack::display()
{
	for (int i = 0; i < top + 1; ++i)
	{
		cout << p[i] << ' ';
	}
}

bool stack::empty()
{
	return top == -1;
}

class stackMin
{
	stack s1, s2;
public:
	stackMin() {}
	~stackMin() {}
	int min()
	{
		if (s2.empty())	return 100;
		else return s2.pop();
	}
	void push(int val)
	{
		s1.push(val);
		if (val < min()) s2.push(val);
	}
	void display()
	{
		s1.display();
		cout << endl;
		s2.display();
		cout << endl;
	}
};

void main()
{
	stackMin s;
	for (int i = 2; i < 10; ++i)
	{
		s.push(3 * i);
	}
	for (int i = 1; i < 10; ++i)
	{
		s.push(3 * i);
	}
	s.display();
}
