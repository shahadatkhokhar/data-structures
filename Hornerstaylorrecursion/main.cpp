#include <iostream>

using namespace std;

double e(double x,double n)
{
    double s=1;
    for(;n>0;n--)
        s=1+x/n*s;

    return s;
}

double e(double x, double n, bool r) // for calling recursive function
{
    static double s=1;

    if(n==0)
        return 1;
    else
    {
        s=1+x/n*s;
        return e(x,n-1);
    }
}
int main()
{
    double ans;
    ans = e(4,15,true);
    cout<<ans;
    return 0;
}
