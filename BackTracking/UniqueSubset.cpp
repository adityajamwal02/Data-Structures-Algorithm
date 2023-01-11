/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in ascending order.
Input Format
In the function an integer vector is passed.
Output Format
Return a vector of vectors containing unique subsets.

Sample Input
[1,2,2]

Sample Output
[[],[1],[1,2],[1,2,2],[2],[2,2]]
*/


#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;

void helper(vector<int> &nums, vector<int> v, int i){
    if(i==nums.size()){
        sort(v.begin(), v.end());
        s.insert(v);
        return;
    }
    v.push_back(nums[i]);
    helper(nums,v,i+1);
    v.pop_back();
    helper(nums,v,i+1);
}
vector<vector<int>> uniqueSubsets(vector<int> nums){
    s.clear();
    vector<int> v;
    vector<vector<int>> ans;
    helper(nums, v, 0);
    for(auto x: s){
        ans.push_back(x);
    }
    return ans;
}
