#include <iostream>
#include <cstring>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* init(int a[], int n)
{
	node *head=new node(), *q = new node();
	for (int i = 0; i < n; ++i)
	{
		node *p = new node();
		p->data = a[i];
		if (i == 0) { q = p; head = p; }
		q->next = p;
		q = p;
	}
	return head;
}

void removeDuplicate(node* head)
{
	node *p, *q, *c;
	c = head;
	while (c)
	{
		int v=c->data;
		p = c;
		q = p->next;
		while (q)
		{
			if (q->data == v)
			{
				p->next=q->next;
				q = p->next;
			}
			else
			{
				p = p->next;
				q = p->next;
			}
		}
		c = c->next;
	}
}

void print(node* head)
{
	while (head)
	{
		cout << head->data << ' ';
		head = head->next;
	}
}

int main()
{
	int a[] = { 1, 1, 2, 2, 5, 3, 4, 5, 6, 7, 8, 8, 8, 1, 2 };
	int n = 15;
	node *head=init(a, n);
	removeDuplicate(head);
	print(head);
	cout << endl;
	return 0;
}
