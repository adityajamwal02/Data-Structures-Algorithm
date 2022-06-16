#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countComposite(int n)
{
    if(n<4&&n!=0)
        cout<<"-1";

    int rem=n%4==0;

    if(rem==0)
    {
        cout<<n/4;
    }
    if(rem==1)
    {
        if(n<9)
            cout<<"-1";

        cout<<(n-9)/4+1;
    }

    if(rem==2)
    {
        cout<<(n-6)/4+1;
    }

    if(rem==3)
        cout<<(n-15)/4+2;
}

int main()
{
    int n;
    cout<<"\n Enter The Value that you want to split: ";
    cin>>n;
    countComposite(n);
}
