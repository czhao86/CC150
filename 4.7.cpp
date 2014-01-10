#include <iostream>
#include <map>
using namespace std;

struct Node
{
	int key;
	Node *parent, *lchild, *rchild;
};

Node *p, b[24], *head, *head1, *head2;
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

bool sametree(Node* a, Node* b)
{
	if (a == NULL && b == NULL) return true;
	else if (a == NULL || b == NULL) return false;
	else if (a->key == b->key)
	{
		return (sametree(a->lchild, b->lchild) && sametree(a->rchild, b->rchild));
	}
	else return false;
}

bool subtree(Node* n1, Node* n2)
{
	if (n1 == NULL) return false;
	if (n1->key==n2->key) return sametree(n1,n2);
	else return (subtree(n1->lchild, n2) || subtree(n1->rchild, n2));
	return false;
}

int main()
{
	init();
	head1 = NULL;
	int a[] = { 5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12 };
	for (int i = 0; i < 12; ++i)
	{
		insert(head1, a[i]);
	}
	head2 = NULL;
	int aa[] = { 3, 1, 4, 2};
	for (int i = 0; i < 4; ++i)
	{
		insert(head2, aa[i]);
	}	
	cout<<sametree(head1, head2)<<endl;
	cout << subtree(head1, head2) << endl;
	return 0;
}
