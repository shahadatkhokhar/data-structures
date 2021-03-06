#include <iostream>

using namespace std;
int fact_r(int n)
{
    if(n==0)
        return 1;
    else
        return fact_r(n-1)*n;
}

int fact_i(int n)
{
    int i,f=1;
    for(i=2;i<=n;i++)
        f*=i;
    return f;
}
int main()
{
    int r;
    r=fact_r(6);
    cout<<r;
    return 0;
}
