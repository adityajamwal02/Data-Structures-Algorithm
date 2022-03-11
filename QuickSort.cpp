#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition_arr(int arr[], int low, int high)
{
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partition_arr(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void printarr(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
        cout<<arr[i]<<" ";
}

int main()
{

    int arr[]={1,4,24,1,4,1,1,5,7,3,78,3,2};
    int n=sizeof(arr)/sizeof(int);
    printarr(arr,n);
    quicksort(arr,0,n-1);
    cout<<"\n AFTER:"<<endl;
    printarr(arr,n);
    return 0;
}
