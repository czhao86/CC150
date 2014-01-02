#include <iostream>
using namespace std;

class stack
{
	int top, size;
	int *p;
public:
	stack(int size = 100);
	~stack();
	int pop();
	void push(int num);
	void display();
	bool empty();
	bool full();
};

stack::stack(int size)
{
	top = -1;
	p = new int[100];
	size = 100;
}

stack::~stack()
{
	delete[] p;
}

int stack::pop()
{
	int x = p[top];
	return x;
	top--;
}

void stack::push(int num)
{
	p[top+1] = num;
	top++;
}

void stack::display()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << p[i] << ' ';
	}
}

bool stack::empty()
{
	return top == -1;
}

bool stack::full()
{
	return top == 9;
}

class setofStacks
{
	stack* s;
	int current;
public:
	setofStacks(int size=10)
	{
		s = new stack[10];
		current = 0;
	}
	~setofStacks() { delete[] s; }
	void push(int num)
	{
		if (s[current].full()) ++current;
		s[current].push(num);
	}
	int pop()
	{
		if (s[current].empty()) --current;
		s[current].pop();
	}
	void display()
	{
		s[0].display();
		cout << endl;
		s[1].display();
		cout << endl;
		s[2].display();
		cout << endl;
	}
	int popAt(int no)
	{
		return s[no].pop();
	}
};

void main()
{
	setofStacks ss;
	for (int i = 0; i < 50; ++i)
	{
		ss.push(i);
	}
	ss.display();
	cout << ss.popAt(1);
}
