#include <iostream>

using namespace std;
int cnt;
int toh(int n, int A, int B, int C)
{
    if(n>0)
    {
        toh(n-1,A,C,B);
        cout<<"From "<<A<<" to "<<C<<endl;
        cnt++;
        toh(n-1,B,A,C);
    }
}
int main()
{
    toh(3,1,2,3);
    cout<<cnt;
    return 0;
}
