#include <stdio.h>
#include <stdlib.h>

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

struct Queue{
	int size;
	int front;
	int rear;
	struct Node **Q;

};

void create(struct Queue *q,int size)
{
	q->size=size;
	q->front=q->rear=0;
	q->Q=(struct Node *)malloc(q->size*sizeof(struct Node *));

}

void enqueue(struct Queue *q,struct Node *x)
{
	if((q->rear+1)%q->size==q->front)
		printf("Queue is full\n");
	else{
		q->rear=(q->rear+1)%q->size ;
		q->Q[q->rear]=x;
	}
}

struct Node * dequeue(struct Queue *q)
{
	struct Node *x=NULL;
	if(q->front==q->rear)
		printf("Queue is empty\n");
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}
int isEmpty(struct Queue q )
{
	return q.front==q.rear;
}

struct Node *root=NULL;

void Treecreate()
{
	struct Node *p,*t;
	int x;
	struct Queue q;
	create(&q, 100);

	printf("Enter root Value");;
	scanf("%d",&x);
	root=(struct Node *)malloc(sizeof(struct Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);

	while(!isEmpty(q))
	{
		p=dequeue(&q);
		printf("Enter left child of %d:",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->lchild=t->rchild=NULL;
		p->lchild=t;
		enqueue(&q,t);
		}
		printf("Enter Right child of %d:",p->data);
		scanf("%d",&x);
		if(x!=-1)
		{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=x;
		t->lchild=t->rchild=NULL;
		p->rchild=t;
		enqueue(&q,t);
		}
	}
}

void Inorder(struct Node *p)
{
	if(p)
	{
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}


void preorder(struct Node *p)
{
	if(p)
	{
		printf("%d ",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void Postorder(struct Node *p)
{
	if(p)
	{

		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ",p->data);
	}
}

int main()
{
    Treecreate();
    preorder(root);
    printf("\nPost Order\n");
    Postorder((root));
    printf("\nIn Order\n");
    Inorder(root);

    return 0;
}
