#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
	int key;
	Node *parent, *lchild, *rchild;
};

Node *head, *p, node[100];
int n;

void init()
{
	head = NULL;
	p = NULL;
	memset(node,'\0',sizeof(node));
	n = 0;
}

void insert(Node* &head, int a)
{
	if (head == NULL)
	{
		node[n].key = a;
		node[n].parent = p;
		head=&node[n];
		n++;
		return;
	}
	p = head;
	if (a > head->key)
		insert(head->rchild, a);
	else
		insert(head->lchild, a);
}

int height(Node *head)
{
	if (head == NULL) return 0;
	return fmax(height(head->lchild), height(head->rchild)) + 1;
}

bool balance(Node *head)
{
	if (head == NULL) return true;
	if (abs(height(head->lchild) - height(head->rchild)) > 1) return false;
	else return (balance(head->lchild) && balance(head->rchild));
}

int main()
{
	init();
	int a[] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
	for (int i = 0; i < 12; ++i)
	{
		insert(head, a[i]);
	}
	cout << height(head) << endl;
	cout<<balance(head)<<endl;
	return 0;
}
