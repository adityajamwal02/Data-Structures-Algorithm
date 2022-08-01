#include<iostream>
using namespace std;

int gcd(int n1, int n2)
{
    while(n2!=0)
    {
        int rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    return n1;
}


int main()
{
    int n1,n2;
    cin>>n1>>n2;

    cout<<gcd(n1,n2);
    return 0;
}
