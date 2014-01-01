#include <iostream>
using namespace std;

class stack3
{
	int top, size;
	int *p;
public:
	stack3(int=0);
	~stack3();
	int pop();
	void push(int num);
	void display();
};

stack3::stack3(int size)
{
	top = -1;
	p = new int[size];
}

stack3::~stack3()
{
	if (p!=0) delete[] p;
}

int stack3::pop()
{
	int x = p[top];
	size--;
	top--;
	return x;
}

void stack3::push(int num)
{
	size++;
	top++;
	p[top] = num;
}

void stack3::display()
{
	for (int i = 0; i < top; ++i)
	{
		cout << p[i] << endl;
	}
}

void main()
{
	stack3 s;
	s.push(1);
	s.display();
}
