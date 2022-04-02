#include<iostream>
using namespace std;
char board[3][4]=
{
    {'a','b','c','e'},
    {'s','f','c','s'},
    {'a','d','e','e'},
};

bool find(int i, int j, string s)
{
    if(s.empty())
        return true;
    if(i-1>=0)
        if(board[i-1][j]==s[0])
        {
            board[i-1][j]='-';
            if(find(i-1,j,s.substr(1)))
               return true;
            else
            board[i-1][j]=s[0];
        }
    if(i+1<3)
        if(board[i+1][j]==s[0])
        {
            board[i+1][j]='-';
            if(find(i+1,j,s.substr(1)))
                return true;
            else
                board[i+1][j]=s[0];
        }
    if(j-1>=0)
        if(board[i][j-1]==s[0])
        {
            board[i][j-1]='-';
            if(find(i,j-1,s.substr(1)))
               return true;
            else
            board[i][j-1]=s[0];
        }
    if(j+1<4)
        if(board[i][j+1]==s[0])
        {
            board[i][j+1]='-';
            if(find(i,j+1,s.substr(1)))
                return true;
            else
                board[i][j+1]=s[0];
        }
         return false;
}

bool sol(string s)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            if(board[i][j]==s[0])
            {
                board[i][j]='-';
                if(find(i,j,s.substr(1)))
                    return true;
                else
                    board[i][j]=s[0];
            }
        return false;
}

int main()
{
    string s;
    cin>>s;
    cout<<sol(s);
    return 0;
}
