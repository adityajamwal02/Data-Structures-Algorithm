#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getmax(int arr[], int n)
{
    int max_e=arr[0];
    for(int i=0;i<n;i++)
    {
        max_e=max(max_e,arr[i]);
    }
    return max_e;
}
void countsort(int arr[],int n,int exp)
{
    int output[n];
    int i, countarr[10]={0};

    for(i=0;i<n;i++)
    {
        countarr[(arr[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        countarr[i]+=countarr[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        output[countarr[(arr[i]/exp)%10]-1]=arr[i];
        countarr[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        arr[i]=output[i];
}
void radixsort(int arr[], int n)
{
    int max_e=getmax(arr,n);
    for(int exp=1;max_e/exp>0;exp*=10)
        countsort(arr,n,exp);
}

int main()
{
    int arr[]={2,4,122,34,98,13,857,43,93,8,4,10,56,199};
    int n=sizeof(arr)/sizeof(int);
    cout<<"\n BEFORE SORTING"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    radixsort(arr,n);
    cout<<"\n AFTER SORTING"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
