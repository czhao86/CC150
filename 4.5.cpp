#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *parent, *lchild, *rchild;
};

Node *head, *p, b[12];
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

int mini(Node* &x)
{
	while (x->lchild)
		x = x->lchild;
	return x->key;
}

int successor(Node* &head)
{
	if (head->rchild) return mini(head->rchild);
	else
	{
		while (head->parent != head->parent->parent->lchild)
		{
			head = head->parent;
		}
		return head->parent->parent->key;
	}
}

int main()
{
	init();
	int a[] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
	for (int i = 0; i < 12; ++i)
	{
		insert(head, a[i]);
	}
	cout << successor(head->rchild) << endl;
	return 0;
}
