#include<iostream>
using namespace std;

#define N 4

bool MazeUtil(int maze[N][N], int x, int y, int soln[N][N]);

void printsolution(int soln[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<soln[i][j];
        cout<<endl;
    }
}
bool issafe(int maze[N][N], int x, int y)
{
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1)
        return true;

    return false;
}

bool solveMaze(int maze[N][N])
{
    int soln[N][N] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };

    if(MazeUtil(maze,0,0,soln)==false)
    {
        cout<<"\n Solution Not exists";
        return false;
    }
    printsolution(soln);
    return true;
}

bool MazeUtil( int maze[N][N], int x, int y, int soln[N][N])
{
    if (x==N-1 && y==N-1 && maze[x][y]==1)
    {
        soln[x][y]=1;
        return true;
    }
    if(issafe(maze,x,y)==true)
    {
        if(soln[x][y]==1)
            return false;

        soln[x][y]=1;

        if(MazeUtil(maze,x+1,y,soln)==true)
            return true;
        if(MazeUtil(maze,x,y+1,soln)==true)
            return true;

        soln[x][y]=0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = { { 1, 1, 1, 1 },
                    { 1, 1, 0, 1 },
                    { 0, 1, 0, 0 },
                    { 1, 1, 1, 1 } };

    solveMaze(maze);
    return 0;
}
