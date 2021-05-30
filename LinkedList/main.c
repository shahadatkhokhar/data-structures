#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next=NULL;
		last->next = t;
		last=t;
	}
}

void create2(int A[], int n)
{
	int i;
	struct Node *t, *last;
	second = (struct Node *)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next=NULL;
		last->next = t;
		last=t;
	}
}

void Display(struct Node *p)
{
	printf("\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void RDisplay(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->data);
		RDisplay(p->next);
	}
}
int count(struct Node *p)
{
	int c=0;
	while(p!=0)
	{
		c++;
		p=p->next;
	}
	return c;
}
//using recursion
int Rcount(struct Node *p)
{
	if(p==0)
		return 0;
	else
		return Rcount(p->next)+1;
}

int Add(struct Node *p)
{
	int sum=0;
	while(p)
	{
		sum+=p->data;
		p=p->next;
	}
	return sum;

}
//sum using recursion
int RAdd(struct Node *p)
{
	if(p==0)
		return 0;
	else
		return RAdd(p->next) + p->data;
}
int Max(struct Node *p)
{
	int m= -32768;

	while(p)
	{
		if(p->data>m)
			m=p->data;
		p=p->next;
	}
	return m;
}

//max using recursion
int RMax(struct Node *p)
{
	int m= -32768;
	int x=0;
	if(p==0)
		return m;
	else
	{
		x = RMax(p->next);
		if(x>p->data)
			return x;
		else
			return p->data;
	}

}
//linear search
struct Node * Search(struct Node *p,int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
			return p;
		p=p->next;
	}
	return NULL;
}

//linear search using recursion
struct Node * RSearch(struct Node *p, int key)
{
	if(p==NULL)
		return NULL;
	if(key==p->data)
		return p;
	return RSearch(p->next,key);
}


void Insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;
	if(index<0||index>count(p))
		return;
	t=(struct Node *)malloc(sizeof(struct Node));
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

void SortedInsert(struct Node *p,int x)
{
	struct Node *t,*q=NULL;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	t->next = NULL;

	if(first==NULL)
		first = t;

	else
	{
		while(p&&p->data<x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next = first;
			first = t;
		}
		else
		{
			t->next=q->next;
			q->next=t;
		}
	}
}

void Delete(struct Node *p,int index)
{
	struct Node *q=NULL;
	int x=-1,i;
	if(index<1||index>count(p))
		return -1;
	if(index==1)
	{
		q=first;
		x=first->data;
		first = first->next;
		free(q);
		return x;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		 free(p);
		return x;
	}
}

void reverse1(struct Node *p)
{
	int *A,i=0;
	struct Node *q;
	A=(int *)malloc(sizeof(int)*count(p));
	q=p;
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=p;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
}

void reverse2(struct Node *p)
{
	struct Node *q, *r;
	q=r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

void reverse3(struct Node *q, struct Node *p)
{
	if(p)
	{
		reverse3(p,p->next);
		p->next=q;
	}
	else
		first=q;
}

void concat(struct Node *p,struct Node *q)
{
	third = p;
	while(p->next!=NULL)
		 p=p->next;

	p->next=q;
}

void Merge(struct Node *p,struct Node *q)
{
	struct Node *last;
	if(p->data<q->data)
	{
		third=last=p;
		p=p->next;
		last->next=NULL;
	}
	else
	{
		third=last=q;
		q=q->next;
		last->next=NULL;
	}
	while(p&&q)
	{
		if(p->data < q->data)
		{
			last->next = p;
			last=p;
			p=p->next;
			last->next=NULL;
		}
		else
		{
			last->next = q;
			last=q;
			q=q->next;
			last->next=NULL;
		}
	}
	if(p) last->next = p;
	if(q) last->next = q;
}

int isLoop(struct Node *f)
{
	struct Node *p,*q;
	p=q=f;
	do
	{
		p=p->next;
		q=q->next;
		q=q!=NULL?q->next:NULL;
	}while(p&&q && p!=q);
	return p==q?1:0;

}
int main()
{
	struct Node *t1, *t2;
	int A[] = {10, 20, 30, 40, 50};
	create(A,5);

	//t1=first->next->next;
	//t2=first->next->next->next->next;;
	//t2->next=t1;
	printf("%d",isLoop(first));



    return 0;
}
