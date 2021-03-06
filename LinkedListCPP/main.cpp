#include <iostream>

using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

class LinkedList
{
	private:
		Node *first;

	public:
		LinkedList()
		{
			first=NULL;
		}
		LinkedList(int A[],int n);
		~LinkedList();

		void Display();
		void Insert(int index, int n);
		int Delete(int index);
		int Length();
};

LinkedList::LinkedList(int A[], int n)
{
	int i;
	Node *t, *last;
	first = new Node;
	first->data = A[0];
	first->next = NULL;
	last = first;

	for(i=1;i<n;i++)
	{
		t=new Node;
		t->data = A[i];
		t->next=NULL;
		last->next = t;
		last=t;
	}
}
LinkedList::~LinkedList()
{
	Node *p=first;
	while(first)
	{
		first=first->next;
		delete p;
		p=first;
	}
}

void LinkedList::Display()
{
	Node *p=first;
	cout<<endl;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

int LinkedList::Length()
{
	int c=0;
	Node *p=first;
	while(p!=0)
	{
		c++;
		p=p->next;
	}
	return c;
}

void LinkedList::Insert(int index,int x)
{
	Node *t,*p=first;
	int i;
	if(index<0||index> Length())
		return;
	t=new Node;
	t->data = x;
	if(index==0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(i=0;i<index-1&&p;i++)
			p=p->next;

		t->next = p->next;
		p->next = t;
	}

}

int LinkedList::Delete(int index)
{
	Node *q=NULL,*p;
	int x=-1,i;
	if(index<1||index>Length())
		return -1;
	if(index==1)
	{
		p=first;
		x=first->data;
		first = first->next;
		delete p;
	}
	else
	{
		p=first;
		for(i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		 delete p;
	}
	return x;
}

int main()
{
	int A[]={1, 2, 3, 4, 5};
	LinkedList l(A,5);

	l.Display();
	l.Insert(2,20);
	l.Display();
	cout<<l.Delete(4);
	l.Display();
	cout<<l.Length();
	return 0;
}
