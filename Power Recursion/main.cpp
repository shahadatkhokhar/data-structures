#include <iostream>

using namespace std;

int pow(int m, int n)
{
    if(n==0)
        return 1;
    else{
        return pow(m,n-1)*m;
    }
}

int powf(int m,int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return powf(m*m,n/2);
    else{
        return m*pow(m*m,(n-1)/2);
    }
}

int main()
{
    int s;

    s = powf(2,9);
    cout<<s;
    return 0;
}
