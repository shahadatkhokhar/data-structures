#include "QueueCpp.h"
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack
{
	int size;
	int top;
	struct Node **S;
};

void StackCreate(struct Stack *st, int size)
{
	st->size=size;
	st->top=-1;
	st->S=(struct Node **)malloc(st->size*(sizeof(struct Node *)));

}

void Display(struct Stack st)
{	int i;
	for(i=st.top;i>=0;i--)
	{
		printf("%d ",st.S[i]);
	}
	printf("\n");
}
void push(struct Stack *st, int x)
{
	if(st->top==st->size-1)
		printf("Stack Overflow\n");
	else
	{
		st->top++;
		st->S[st->top]=x;
	}

}

int pop(struct Stack *st)
{
	int x=-1;
	if(st->top==-1)
		printf("Stack Underflow");
	else
	{
		x=st->S[st->top--];
	}
	return x;
}

int peek(struct Stack st, int index)
{
	int x=-1;
	if(st.top-index+1<0)
		printf("Invalid index\n");
	x=st.S[st.top-index+1];
}
int isEmpty(struct Stack st)
{
	if(st.top==-1)
		return 1;

	return 0;
}

int isFull(struct Stack st)
{
	return st.top==st.size-1;
}

int stackTop(struct Stack st)
{
	if(!isEmpty(st))
		return st.top;

	return -1;
}
#endif // STACK_H_INCLUDED
