#include <iostream>

using namespace std;
class Lowertri
{
	private:
		int *A;
		int n;
	public:
		Lowertri()
		{
			n=2;
			A=new int[2*(2+1)/2];
		}
		Lowertri(int n)
		{
			this->n = n;
			A = new int[n*(n+1)/2];
		}

		void Set(int i, int j, int x);
		int Get(int i, int j);
		void Display();
		int getDimension(){return n;}
		~Lowertri(){delete[] A;}
};

void Lowertri::Set(int i,int j, int x)
{
	if(i>=j)
		A[i*(i-1)/2 + j-1]=x;
		//for column major A[n*(j-1) - (j-2)*(j-1)/2 + i-j] =x;
}

int Lowertri::Get(int i,int j)
{
	if(i>=j)
		return A[i*(i-1)/2 +j-1];
		//for column major return A[n*(j-1) - (j-2)*(j-1)/2 + i-j];
	else return 0;
}

void Lowertri::Display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=j)
				cout<<A[i*(i-1)/2+j-1]<<" ";
				//for column major cout<<A[n*(j-1) - (j-2)*(j-1)/2 + i-j]<<" ";
			else
			cout<<"0 ";
		}
		cout<<"\n";
	}
}
int main()
{
	int d;
	cout<<"Enter Dimension:"; cin>>d;

	Lowertri lm(d);
	cout<<"enter all the elemnts:\n";
	int x;
	for(int i=1;i<=d;i++)
	{
		for(int j=1;j<=d;j++)
		{
		cin>>x;
		lm.Set(i,j,x);
		}
	}
	lm.Display();
    return 0;
}
