#include <iostream>

using namespace std;

int fact(int n)
{
    if(n==0)return 1;
    return fact(n-1)*n;
}

int nCr(int n,int r)
{
    if(r==0||n==r)
        return 1;
    else
        return nCr(n-1,r-1) + nCr(n-1,r);
}

int nCr(int n, int r, bool p)
{
    int t1,t2,t3;
    t1=fact(n);
    t2 = fact(r);
    t3 = fact(n-r);

    return t1/(t2*t3);
}


int main()
{
   int n;
   n=nCr(4,2);
   cout<<n;
    return 0;
}
