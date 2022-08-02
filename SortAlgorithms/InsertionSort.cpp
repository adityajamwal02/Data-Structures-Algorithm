#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[], int n)
{
    int i,j,key;
    for(i=0;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 and arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void printarr(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={4,2,7,6,9,2,1,8,5,4,8,6};
    int n=sizeof(arr)/sizeof(int);
    cout<<" BEFORE SORTING"<<endl;
    printarr(arr,n);
    insertionsort(arr,n);
    cout<<"\n AFTER SORTING"<<endl;
    printarr(arr,n);
}
