/*
In simple bubble sort algorithm, the time complexity will remain O(n^2) every time, even if the given array is already sorted.
Your task is to optimized the bubble sort such that its best case time complexity becomes O(n).
Input Format
In the function an integer vector is passed.
Output Format
Return an integer vector in non decreasing order.

Sample Input
{1, 3, 5, 7, 9}

Sample Output
{1, 3, 5, 7, 9}}

Explanation
given vector is already sorted
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v){
    int n=v.size();
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapped=true;
            }
        }
        if(swapped==false) break;
    }
    return v;
}
