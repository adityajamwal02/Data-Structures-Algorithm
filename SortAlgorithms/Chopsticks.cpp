/*
Given N sticks and an array length where each length[i] represents length of each stick. Your task is to make maximum number of pairs of these sticks such that the difference between the length of two sticks is at most D. A stick can't be part of more than one pair of sticks.
Input Format
In the function an integer vector length and number D is passed.
Output Format
Return an integer representing total number of such pairs.

Sample Input
{1, 3, 3, 9, 4}, x = 2
Sample Output
2
Explanation
(1st, 3rd) and (2nd, 5th) can be paired together.
*/

#include<bits/stdc++.h>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    sort(length.begin(), length.end());
    int result=0;
    for(int i=0;i<length.size()-1;i++){
        if(length[i+1]-length[i]<=D){
            result++;
            i++;
        }
    }
    return result;
}
