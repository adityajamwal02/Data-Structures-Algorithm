/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where its mice is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its mice.
Input Format
Given vector of strings representing a grid with N rows and M columns.
'X' in position (i,j) denotes that the cell is blocked and 'O' denotes that the cell is empty.
Output Format
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.

Sample Input
5 4
OXOO
OOOX
XOXO
XOOX
XXOO

Sample Output
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 0
0 0 1 1
*/


#include<bits/stdc++.h>
using namespace std;

void ratchase(vector<string> a,vector<vector<int>> &b,vector<vector<int>> &v,int i,int j,int n,int m){
	if(i==n && j==m){
		for(int k=0;k<=n;k++){
			for(int l=0;l<=m;l++){
				v[k][l] = b[k][l];
			}cout<<endl;
		}
		return;
	}
	if(i!=n && a[i+1][j]!='X' && b[i+1][j]!=1){
		b[i+1][j]=1;
		ratchase(a,b,v,i+1,j,n,m);
		b[i+1][j]=0;
	}
	if(i>0 && a[i-1][j]!='X' && b[i-1][j]!=1){
		b[i-1][j]=1;
		ratchase(a,b,v,i-1,j,n,m);
		b[i-1][j]=0;
	}
	if(j!=m && a[i][j+1]!='X' && b[i][j+1]!=1){
		b[i][j+1]=1;
		ratchase(a,b,v,i,j+1,n,m);
		b[i][j+1]=0;
	}
	if(j>0 && a[i][j-1]!='X' && b[i][j-1]!=1){
		b[i][j-1]=1;
		ratchase(a,b,v,i,j-1,n,m);
		b[i][j-1]=0;
	}
	return;
}
vector<vector<int>> ratAndMice(vector<string> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> v(n, vector<int>(m, 0));
    vector<vector<int>> b(n, vector<int>(m, 0));
    b[0][0] = 1;

	ratchase(a,b,v,0,0,n-1,m-1);
	return v;
}
