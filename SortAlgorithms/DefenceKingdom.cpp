/*
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells.
The player builds crossbow towers in some cells of the grid.
The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.
Your task is to find the penalty of the give position.

Input Format
In the function an width and height of the kingdom and a vector of pairs representing positions of towers is passed.
Output Format
Return an integer representing the number of cells in the largest rectangle that is not defended by the towers.

Sample Input
15 8
{(3, 8), (11, 2), (8, 6)}
Sample Output
12
*/

#include<bits/stdc++.h>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    vector<pair<int,int>> v=position;
    vector<int> x,y;
    x.push_back(0);
    y.push_back(0);
    int maxx=INT_MIN, maxy=INT_MIN;
    for(int i=0;i<v.size();i++){
        x.push_back(v[i].first);
        y.push_back(v[i].second);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i=1;i<x.size();i++){
        maxx=max(maxx,x[i]-x[i-1]-1);
        maxy=max(maxy,y[i]-y[i-1]-1);
    }
    maxx=max(maxx,W-x[x.size()-1]);
    maxy=max(maxy,H-y[y.size()-1]);
return (maxx*maxy);
}
