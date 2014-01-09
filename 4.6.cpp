#include <iostream>
#include <map>
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

Node* ancestor(Node* n1, Node* n2)
{
	map<Node*, bool> m;
	while (n1->parent)
	{
		m[n1->parent] = true;
		n1 = n1->parent;
	}
	while (n2 && !m[n2])
	{
		n2=n2->parent;
	}
	return n2;
}

bool father(Node* f, Node* c)
{
	if (f == NULL) return false;
	else if (f == c) return true;
	else return (father(f->lchild, c) || father(f->rchild, c));
}

Node* ancestor2(Node* n1, Node* n2)
{
	while (n1)
	{
		if (father(n1, n2)) return n1;
		n1 = n1->parent;
	}
}

void ancestor3(Node* head, Node* n1, Node* n2, Node* &ans)
{
	if (head == NULL) return;
	if (father(head, n1) && father(head, n2))
	{
		ans = head;
		ancestor3(head->lchild, n1, n2, ans);
		ancestor3(head->rchild, n1, n2, ans);
	}
}

Node* search(Node* head, int n)
{
	if (head->key == n) return head;
	else
	{
		if (n>head->key) search(head->rchild, n);
		else search(head->lchild, n);
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
	cout << (ancestor2(head->lchild->lchild, head->rchild->rchild)->key) << endl;
	Node *answ = NULL;
	Node *x = search(head, 1), *y = search(head, 10);
	ancestor3(head, head->lchild->lchild, head->rchild->rchild, answ);
	ancestor3(head, x, y, answ);
	cout << answ->key << endl;
	return 0;
}
