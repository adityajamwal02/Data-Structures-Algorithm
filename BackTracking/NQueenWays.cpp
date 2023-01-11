/*
You are given an empty chess board of size N*N. Find the number of ways to place N queens on the board, such that no two queens can kill each other in one move. A queen can move vertically, horizontally and diagonally.

Input Format:
In the function you are given an integer N as a parameter.
Output Format:
Return the number of possible solutions.

Constraints:
1<=N<=10

Sample Testcase 1:
Input:
4
Output:
2
Sample Testcase 2:
Input:
1
Output:
1
*/

#include <bits/stdc++.h>
using namespace std;


int cnt;

int isSafe(int N, int mat[][20], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 1) {
            return 0;
        }
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 1) {
            return 0;
        }
    }

    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (mat[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

void solve(int N,int mat[][20], int r)
{
    if (r == N)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(N, mat, r, i))
        {
            mat[r][i] = 1;
            solve(N,mat, r + 1);
            mat[r][i] = 0;
        }
    }
}


int nQueen(int n){
    cnt =0;
    int arr[20][20]={0};

    solve(n,arr,0);
    return cnt;

}
