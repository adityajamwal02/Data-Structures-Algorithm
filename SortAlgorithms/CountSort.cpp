#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n)             //Function CountSort
{
    int max_size=arr[0];                    //Initialize maximum element from array
    for(int i=0;i<n;i++)
    {
        max_size=max(max_size,arr[i]);      //Getting max element and using this max element to make another array
    }
    int countarr[max_size]={0};             //Count Array of Max size
    for(int i=0;i<n;i++)                    //Loop for counting the element repeating in array
    {
        countarr[arr[i]]++;
    }

    for(int i=1;i<=max_size;i++)            //Now Adding the Countarr[i] with countarr[i-1] throughout max element size
    {
        countarr[i]+=countarr[i-1];
    }
    int output[n];                          //Output array From last element
    for(int i=n-1;i>=0;i--)
    {
        output[--countarr[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
int main()
{
    int arr[]={2,3,5,2,1,5,7,4,3,2,5,1,1,9,7,4,2,1};
    int n=sizeof(arr)/sizeof(int);
    cout<<"\n BEFORE SORTING: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    countsort(arr,n);
    cout<<"\n AFTER SORTING: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
