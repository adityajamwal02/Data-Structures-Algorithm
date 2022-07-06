#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int rotatedsearch(vector<int> arr,int key)
{
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(arr[mid]==key)
            {
                return mid;
            }
            if(arr[s]<=arr[mid])
            {
                if(key>=arr[s] and key<=arr[mid])
                    e=mid-1;
                else
                    s=mid+1;
            }
            else
            {
                if(key>=arr[mid] and key<=arr[e])
                    s=mid+1;
                else
                    e=mid-1;
            }
        }
        return -1;
}

int main()
{
    vector<int> arr{4,5,6,7,0,1,2,3};
    int key;
    cin>>key;
    cout<<"Element Present at: "<<rotatedsearch(arr,key)<<" index"<<endl;
}
