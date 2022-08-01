#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;

void mergesort(int arr[], int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarr(int arr[], int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[]={9,3,2,7,1,5,8,4,2,1,11,23,8,5,3,4,95,17,56};
    int n=sizeof(arr)/sizeof(int);
    cout<<" ORIGINAL ARRAY"<<endl;
    printarr(arr, n);
    mergesort(arr, n);
    cout<<"\n SORTED ARRAY"<<endl;
    printarr(arr, n);

}
