#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void fillarray(int arr[], int i, int n, int value)
{
    if(i==n)        //base case
    {
        printarray(arr,n);
        return;
    }
    arr[i]=value;
    fillarray(arr,i+1,n,value+1);

    //backtracking step to get negative of each number in an array
    arr[i]=-1*arr[i];
}

int main()
{
    int arr[]={0};
    int n;
    cin>>n;
    fillarray(arr,0,n,1);
    printarray(arr,n);
}
