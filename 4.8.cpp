#include <iostream>
#include <map>
using namespace std;

struct Node
{
	int key;
	Node *parent, *lchild, *rchild;
};

Node *p, b[24], *head;
int m;

void init()
{
	memset(b, '\0', sizeof(b));
	m = 0;
	head = p = NULL;
}

void insert(Node* &head, int a)
{
	if (head == NULL)
	{
		b[m].key = a;
		b[m].parent = p;
		head = &b[m];
		m++;
		return;
	}
	p = head;
	if (a > head->key)
		insert(head->rchild, a);
	else
		insert(head->lchild, a);
}

void treepath(Node* a, int sum)
{
	if (a == NULL) return;
	Node* x = a;
	Node* y = a;
	int total = 0;
	for (int i = 0; x != NULL;++i)
	{
		total += x->key;
		if (total == sum)
		{
			for (int j = 0; j < i+1; ++j)
			{
				cout << y->key << ' ';
				y = y->parent;
			}
			cout << endl;
		}
		x = x->parent;
	}
	treepath(a->lchild, sum);
	treepath(a->rchild, sum);
}

int main()
{
	init();
	int a[] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
	for (int i = 0; i < 12; ++i)
	{
		insert(head, a[i]);
	}
	treepath(head, 13);
	return 0;
}
