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
	q->next=head->next->next->next->next;
	return head;
}

int loopStart(node* head)
{
	node *p1 = head->next;
	node *p2 = head->next->next;
	node *p3 = head;
	while(p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	while (p3!=p2)
	{
		p3 = p3->next;
		p2 = p2->next;
	}
	return p3->data;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;
	node *head = init(a, n);
	int ls = loopStart(head);
	cout << ls<< endl;
	return 0;
}
