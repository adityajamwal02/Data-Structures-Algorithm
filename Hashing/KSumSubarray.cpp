/*
In this challenge, we are given an array and we need to find out the length of longest subarray whose sum is equal to given integer K.

Sample Input
arr = { 0,-2,1,2,3,4,5,15,10,5 }
K = 15
Sample output
5
Explanation
The following subarray has the sum 15 and is the longest.
1,2,3,4,5

Expected Complexity
O(N)
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayKSum(vector<int> arr,int k){

    int n=arr.size();
    unordered_map<int, int> mp;
    int previous=0;
    int length=0;
    for(int i=0;i<n;i++){
        previous+=arr[i];
        if(previous==k){
            length=max(length,i+1);
        }
        if(mp.find(previous-k)!=mp.end()){
            length=max(length, i-mp[previous-k]);
        }else{
            mp[previous]=i;
        }
    }
return length;
}
