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

void add(node* head1, node* head2)
{
	for (int i = 0; i < 15; ++i)
	{
		head2->data = head1->data + head2->data;
		if (head2->data >= 10)
		{
			head2->data = head2->data - 10;
			head1->next->data++;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
}

int main()
{
	int a[] = { 1, 1, 2, 2, 5, 3, 4, 5, 6, 7, 9, 8, 8, 1, 2 };
	int b[] = { 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 5, 3, 2, 6, 3 };
	int n = 15;
	node *head1 = init(a, n);
	node *head2 = init(b, n);
	add(head1, head2);
	while (head2)
	{
		cout << head2->data << ' ';
		head2 = head2->next;
	}
	return 0;
}
