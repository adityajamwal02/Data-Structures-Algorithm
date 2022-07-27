#include<iostream>
using namespace std;

// In this method Time complexity is upto 2^(m+n) time [recursion]
// We can reduce it to m*n time by using DP {make a table and use recursion function within itself}
// BEST WAY: To make a formula --> PnC : No. of way to make these grid ways = (m-1+n-1)! / (m-1)! * (n-1)!   [gives ans. in O(m+n) time}


int gridways(int i, int j, int m, int n)
{
    if(i==m and j==n)
        return 1;

    if(j>n or i>m)
        return 0;

    int ans = gridways(i+1,j,m,n) + gridways(i,j+1,m,n);
    return ans;

}


int main()
{
    int n,m;
    cin>>n>>m;


    cout<<gridways(0,0,m-1,n-1);

    return 0;
}
