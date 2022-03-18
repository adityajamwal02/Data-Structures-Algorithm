#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int key;
    cout<<"Enter Key to Find"<<endl;
    cin>>key;
    arr.push_back(8); arr.push_back(9); arr.push_back(10);
    vector<int>::iterator it=find(arr.begin(),arr.end(),key); //Find Inbuilt fn uses linear search: works well with unsorted array too//
    if(it!=arr.end())
    {
        cout<<"Array present at: "<<it-arr.begin();
    }
    else
    {
    cout<<"Array Element Not Found"<<endl;
    }

}
