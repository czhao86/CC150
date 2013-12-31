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

node* nth(node* head, int n)
{
	node *p1 = head;
	for (int i = 0; i < n; ++i)
	{
		head = head->next;
	}
	node *p2 = head;
	while (p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}

int main()
{
	int a[] = { 1, 1, 2, 2, 5, 3, 4, 5, 6, 7, 9, 8, 8, 1, 2 };
	int n = 15;
	node *head=init(a, n);
	node *x=nth(head,5);
	cout << x->data<<endl;
	return 0;
}
