/*
Array Intersection!
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result vector in the sorted order.

Example :
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

/// Approach 1

#include<bits/stdc++.h>
#include<set>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s;
    vector<int> result;
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
                s.insert(nums1[i]);
            }
        }
    }
    for(auto x: s){
        result.push_back(x);
    }
    return result;
}

/// Approach 2

#include<bits/stdc++.h>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> map;
        vector<int> result;

        for(int i=0;i<nums1.size();i++)
        {
            map[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(map[nums2[i]] > 0)
            {
                result.push_back(nums2[i]);
                map[nums2[i]] = 0;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
