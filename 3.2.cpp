#include <iostream>
using namespace std;

class stack
{
	int top, size;
	int *p;
public:
	stack(int size= 10);
	~stack();
	int pop();
	void push(int num);
	void display();
	int min();
};

stack::stack(int size)
{
	top = -1;
	p = new int[10];
	size = 10;
}

stack::~stack()
{
	delete[] p;
}

int stack::pop()
{
	int x = p[top];
	top--;
	return x;
}

void stack::push(int num)
{
	p[top+1] = num;
	top++;
}

void stack::display()
{
	for (int i = 0; i < top+1; ++i)
	{
		cout << p[i] << ' ';
	}
}

int stack::min()
{
	int min;
	min = p[0];
	for (int i = 0; i < 10; ++i)
	{
		if (p[i] < min) min = p[i];
	}
	return min;
}

void main()
{
	stack s;
	for (int i = 20; i > 10; --i)
	{
		s.push(i);
	}
	s.display();
	cout << s.min() << endl;
}
