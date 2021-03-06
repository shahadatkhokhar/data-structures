//finding missing elements in and array
#include <stdio.h>
#include <stdlib.h>
//finding single missing element
void findSingle(int A[],int n,int diff)
{
	int i;
    for(i=0;i<n;i++)
    {
		if(A[i]-i!=diff)
		{
			printf("Missing element :%d",i+diff);
			break;
		}
    }
}
//finding multiple
void findMultiple(int A[],int n,int diff)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]-i!=diff)
		{
			while(diff<A[i]-i)
			{
				printf("\nMissing: %d",i+diff);
				diff++;
			}
		}
	}
}

//method 2 for finding multiple missing elements
void findMultiple2(int A[],int n, int l, int h)
{
	int i;
	int H[h];
	for(i=1;i<h;i++)
		H[i]=0;
	for(i=0;i<n;i++)
		H[A[i]]++;

	for(i=1;i<=h;i++)
	{
		if(H[i]==0)
			printf("\nMissing:%d",i);
	}
}
int main()
{
	int A[]= {3,7,4,9,12,6,1,11,2,10}, n=10, diff = A[0]-0;
    findMultiple2(A,n,1,12);
    return 0;
}
