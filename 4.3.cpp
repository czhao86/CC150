#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *parent, *lchild, *rchild;
};

Node b[10];
int m;

void init()
{
	memset(b, '\0', sizeof(b));
	m = 0;
}

void binarytree(Node* &head, Node *parent, int a[], int sta, int end)
{
	if (sta <= end)
	{
		int mid = (sta + end) >> 1;
		b[m].key = a[mid];
		b[m].parent = parent;
		head = &b[m++];
		binarytree(head->lchild, head, a, sta, mid - 1);
		binarytree(head->rchild, head, a, mid + 1, end);
	}

}

int depth(Node *head)
{
	if (head == NULL) return 0;
	return fmax(depth(head->lchild),depth(head->rchild))+1;
}

int main()
{
	init();
	int a[] = { 0, 1, 2, 3, 4, 5, 6 };
	Node *head=NULL;
	binarytree(head, NULL, a, 0, 6);
	cout<<depth(head)<<endl;
	return 0;
}
