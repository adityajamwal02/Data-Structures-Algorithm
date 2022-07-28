#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void permute(string a, int l, int r)
{
    if (l==r)
        cout<<a<<endl;
    else
    {
        for (int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);    //swapping
            permute(a, l+1, r); //recursion called
            swap(a[l], a[i]);   //backtrack
        }
    }
}
int main()
{
    string a="123";
    int n=a.size();
    permute(a,0,n-1);
    return 0;
}
