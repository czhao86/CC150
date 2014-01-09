#include <iostream>
#include <list>
#include <vector>
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

vector<list<Node*>> level(Node* &head)
{
	list<Node*> li;
	vector<list<Node*>> lv;
	li.push_back(head);
	lv.push_back(li);
	int level = 0;
	while (!lv[level].empty())
	{
		list<Node*> x;
		list<Node*>::iterator it;
		for (it = lv[level].begin(); it != lv[level].end(); ++it)
		{
			Node *n = *it;
			if (n->lchild) x.push_back(n->lchild);
			if (n->rchild) x.push_back(n->rchild);
		}
		level++;
		lv.push_back(x);
	}
	return lv;
}

void print(vector<list<Node*>> lv)
{
	vector<list<Node*>>::iterator visit;
	for (visit = lv.begin(); visit != lv.end(); ++visit)
	{
		list<Node*> pl = *visit;
		list<Node*>::iterator visi;
		for (visi = pl.begin(); visi != pl.end(); ++visi)
		{
			Node *xx =*visi;
			cout << xx->key<< ' ';
		}
		cout << endl;
	}
}

int main()
{
	init();
	vector<list<Node*>> lv;
	int a[] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
	for (int i = 0; i < 12; ++i)
	{
		insert(head, a[i]);
	}
	lv=level(head);
	print(lv);
	return 0;
}
