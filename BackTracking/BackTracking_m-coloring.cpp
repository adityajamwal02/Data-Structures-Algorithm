#include<iostream>
using namespace std;

#define V 4

void printsolution(int color[]);

bool issafe(int v, bool graph[V][V], int color[], int c)
{
    for(int i=0;i<V;i++)
        if(graph[v][i] && c==color[i])
            return false;
    return true;
}

bool graphUtil(bool graph[V][V], int m, int color[], int v)
{
    if(v==V)
        return true;
    for(int c=1;c<=m;c++)
    {
        if(issafe(v,graph,color,c))
        {
            color[v]=c;
            if(graphUtil(graph,m,color,v+1)==true)
                return true;
            color[v]=0;
        }
    }
    return false;
}

bool graphcolor(bool graph[V][V], int m)
{
    int color[V];
    for(int i=0;i<V;i++)
    {
        color[i]=0;
    }
    if(graphUtil(graph, m, color, 0)==false)
    {
        cout<<" \n Solution not exisiting";
        return false;
    }
    printsolution(color);
    return true;
}

void printsolution(int color[])
{
    cout<<"\n Solution exists \n Assigned colors as follows: \n";
    for(int i=0;i<V;i++)
        cout<<" "<<color[i]<< " ";
    cout<<endl;
}

int main()
{
    bool graph[V][V]= { { 0, 1, 1, 1 },
                        { 1, 0, 1, 0 },
                        { 1, 1, 0, 1 },
                        { 1, 0, 1, 0 }, };
    int m=3;
    graphcolor(graph, m);
    return 0;
}
