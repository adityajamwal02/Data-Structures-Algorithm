#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int l, int r, int x)
{
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid]>x)
            return binarysearch(arr,l,mid-1,x);
        return binarysearch(arr,mid+1,r,x);
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,6,8,9};
    int n=sizeof(arr)/sizeof(int);
    int x=9;
    int result=binarysearch(arr,0,n-1,x);
    (result==-1)? cout<<"\n Element Not Present" : cout<<"\n Element Present at index "<< result;
}
