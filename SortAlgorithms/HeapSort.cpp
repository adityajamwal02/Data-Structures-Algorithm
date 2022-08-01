#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n and arr[l]>arr[largest])
        largest=l;

    if(r<n and arr[r]>arr[largest])
        largest=r;

    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void printarr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={12, 19, 11, 1, 9, 8, 4, 1, 12, 9, 7, 5};
    int n=sizeof(arr)/sizeof(int);
    cout<<"\n Before Swapping"<<endl;
    printarr(arr,n);
    heapsort(arr,n);
    cout<<"\n After Swapping"<<endl;
    printarr(arr,n);

}
