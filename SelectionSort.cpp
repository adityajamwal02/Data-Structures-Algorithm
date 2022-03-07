#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min_idx])
                min_idx=j;
            swap(arr[min_idx],arr[i]);
    }
}
void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={3,-5,2,-9,1,4,3,8,5,0,-2,6,7,8,2};
    int n=sizeof(arr)/sizeof(int);
    cout<<" BEFORE SORTING"<<endl;
    printarr(arr,n);
    selectionsort(arr,n);
    cout<<"\n AFTER SORTING"<<endl;
    printarr(arr,n);
    return 0;
}
