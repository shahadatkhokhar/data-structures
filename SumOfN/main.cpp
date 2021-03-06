#include <iostream>

using namespace std;
int formula(int n)
{
    return (n*(n+1))/2;
}

int loop(int n)
{
    int i,s=0;
    for(i=0;i<=n;i++)
        s+=i;
    return s;
}

int recursion(int n)
{
    if(n==0)
        return 0;
    else
        return recursion(n-1)+n;
}
int main()
{
    int f,l,r;
//    f = formula(100);
  //  cout<<f;

    l=loop(100);
   cout<<l;

    //r = recursion(100);
    //cout<<r;
    return 0;
}
