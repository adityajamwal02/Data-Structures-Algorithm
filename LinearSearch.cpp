#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void linearsearch(int arr[], int n, int key)
{
    int count_e=0;
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            cout<<"Element present at "<<i+1<<" position"<<endl;
            count_e++;
        }
    }
    if(count_e==0)
    {
        cout<<"Element Not Found"<<endl;
    }
    cout<<"Total Occurrence: "<<count_e;
}
int main()
{
    int key;
    cout<<"Enter Element to Find"<<endl;
    cin>>key;
    int arr[]={1,1,5,1,5,1,6,8,9,3,2,1};
    int n=sizeof(arr)/sizeof(int);
    linearsearch(arr,n,key);
}
