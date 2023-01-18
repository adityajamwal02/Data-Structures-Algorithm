
#include<bits/stdc++.h>
using namespace std;

int trappedWater(vector<int> h){
    int n=h.size();
    if(n<=2){
        return 0;
    }
    // Left Max And Right Max Array
    vector<int> left(n,0), right(n,0);
    left[0]=h[0];
    right[n-1]=h[n-1];

    for(int i=1;i<n;i++){
        left[i]=max(left[i-1],h[i]);
        right[n-i-1]=max(right[n-i],h[n-i-1]);
    }

    // water
    int water=0;
    for(int i=0;i<n;i++){
        water+=min(left[i],right[i])-h[i];
    }
    return water;
}

int main(){
    vector<int> heights={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(heights)<<endl;

    return 0;
}
