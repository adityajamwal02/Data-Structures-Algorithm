
/// Two pointer approach

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum){
    vector<vector<int>> result;
    int n=arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0;i<=n-3;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int curr=arr[i];
            curr+=arr[j];
            curr+=arr[k];
            if(curr==sum){
                result.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
            }else if(curr>sum){
                k--;
            }else{
                j++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int sum=15;
    auto result=triplets(arr,sum);
    for(auto v: result){
        for(auto no: v){
            cout<<no<<", ";
        }
        cout<<endl;
    }
return 0;
}
