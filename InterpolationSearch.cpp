#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int interpolation(int arr[],int low,int high, int x)
{
    int position;
    if(low<=high && x>=arr[low] && x<=arr[high])
    {
        position=low+(((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));
        if(arr[position]==x)
            return position;
        if(arr[position]<x)
            return interpolation(arr,position+1,high,x);
        if(arr[position]>x)
            return interpolation(arr,low,position-1,x);
    }
    return -1;
}
int main()
{
    int arr[]={1,4,7,10,13,15,16,19,21,28,29,32};
    int n=sizeof(arr)/sizeof(int);
    int x;
    cout<<"\n Enter Key: ";
    cin>>x;
    int pos=interpolation(arr,0,n-1,x);
    if(pos != -1)
        cout<<"\n Element Found at: "<<pos;
    else
        cout<<"\n Element Not Found";
    return 0;
}
