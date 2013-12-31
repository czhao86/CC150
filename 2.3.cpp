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

void del(node* head, int n)
{
	for (int i = 0; i < n-2; ++i)
	{
		head = head->next;
	}
	node *p = head;
	node *q = p->next;
	p->next = q->next;
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
	int a[] = { 1, 1, 2, 2, 5, 3, 4, 5, 6, 7, 9, 8, 8, 1, 2 };
	int n = 15;
	node *head=init(a, n);
	del(head,5);
	print(head);
	return 0;
}
