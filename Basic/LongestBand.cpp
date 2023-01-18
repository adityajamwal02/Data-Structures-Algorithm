

#include<bits/stdc++.h>
using namespace std;

int longestBand(vector<int> arr){
    int n=arr.size();
    unordered_set<int> s;
    for(int x: arr){
        s.insert(x);
    }
    int LargestLength=1;
    for(auto element: s){
        int parent=element-1;
        if(s.find(parent)==s.end()){
            int next_no=element+1;
            int count=1;

            while(s.find(next_no)!=s.end()){
                next_no++;
                count++;
            }
            if(count>LargestLength){
                LargestLength=count;
            }
        }
    }
    return LargestLength;
}

int main(){
    vector<int> arr{1,9,3,0,18,5,2,10,7,12,16};
    cout<<longestBand(arr);

return 0;
}
