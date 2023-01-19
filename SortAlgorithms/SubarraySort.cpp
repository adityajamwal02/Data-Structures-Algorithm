/// Find the smallest subarray that needs to sorted in place so that entire input array becomes sorted

/// Sorting Approach O(nlogn)
/*
vector<int> subarraySort(vector<int> a){
    vector<int> b(a);
    sort(b.begin(), b.end());
    int i=0, n=a.size();
    while(i<n and a[i]==b[i]){
        i++;
    }
    int j=a.size()-1;
    while(j>=0 and a[j]==b[j]){
        j--;
    }
    if(i==a.size()){
        return {-1,-1};
    }
    return {i,j};
}
*/

#include<bits/stdc++.h>
using namespace std;

bool boolOutOrder(vector<int> arr, int i){
    int x=arr[i];
    if(i==0){
        return x>arr[1];
    }
    if(i==arr.size()-1){
        return x<arr[i-1];
    }
    return x>arr[i] or x<arr[i];
}

pair<int, int> subarraySort(vector<int> arr){

    int smallest=INT_MAX;
    int largest=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int x=arr[i];
        if(boolOutOrder(arr,i)){
           smallest=min(smallest,x);
           largest=max(largest,x);
        }
    }
    if(smallest==INT_MAX){
        return {-1,-1};
    }

    int left=0;
    while(smallest>=arr[left]){
        left++;
    }
    int right=arr.size()-1;
    while(largest<=arr[right]){
        right--;
    }
    return {left, right};
}

int main(){

    vector<int> arr={1,2,3,4,5,8,6,7,9,10,11};
    auto p=subarraySort(arr);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
