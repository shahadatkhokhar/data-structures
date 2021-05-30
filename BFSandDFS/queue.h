#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node{
	int data;
	struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct Node *t =(struct Node *)malloc(sizeof(struct Node));
	if(t==NULL)
		printf("Queue is Full");
	else
	{
		t->data=x;
		t->next=NULL;
		if(front ==NULL)
			front=rear=t;
		else
		{
			rear->next=t;
			rear=t;
		}
	}
}

int dequeue()
{
	int x=-1;
	struct Node *t;

	if(front==NULL)
		printf("Queue is empty");
	else
	{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}
	return x;
}

void isEmpty()
{
    return front==NULL;
}



#endif // QUEUE_H_INCLUDED
