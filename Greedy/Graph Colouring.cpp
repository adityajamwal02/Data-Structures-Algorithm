#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

class graph                             // Graph Creation for Map
{
    int v;
    list<int> *adj;                     // list with adjacent pointer type

public:
    graph(int v)                        // constructor call
    {
        this->v=v;                      // currently pointing vertex to current vertex in memory
        adj=new list<int>[v];
    }
    ~graph()                            // destroying adj pointer after its purpose through destructor
    {
        delete [] adj;
    }
    void addEdge(int v, int w)          // Naming Edges (Adding)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);            // Graph Undirected
    }
    void greedyColouring()              // Colouring part of graph
    {
        int result[v];                  // result array with v no. of vertices
        result[0]=0;                    // First Colour to First Vertex
        for(int u=1;u<v;u++)
            result[u]=-1;               // no color is assigned to u

        bool available[v];
        for(int cr=0;cr<v;cr++)         // Colour availablity
            available[cr]=false;

         for(int u=1;u<v;u++)
         {
            list<int>::iterator i;
            for(i=adj[u].begin();i!=adj[u].end();++i)
                if (result[*i]!=-1)
                    available[result[*i]]=true;

            int cr;
            for (cr=0;cr<v;cr++)
                if (available[cr]==false)
                    break;

            result[u]=cr; // Assign the found color

            // Reset the values back to false for the next iteration
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = false;
        }
          for(int u=0;u<v;u++)
            cout << "Vertex "<< u << " --->  Color "<<result[u]<< endl;
    }
};

int main()
{
    graph g1(10);                   // Considering Only 10 districts in a Map to colour
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(1, 2);
    g1.addEdge(1, 8);
    g1.addEdge(1, 9);
    g1.addEdge(2, 3);
    g1.addEdge(2, 8);
    g1.addEdge(3, 4);
    g1.addEdge(3, 7);
    g1.addEdge(3, 8);
    g1.addEdge(4, 5);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(6, 7);
    g1.addEdge(7, 8);
    g1.addEdge(8, 9);
    cout << "Coloring of Districts of Map \n \n";
    g1.greedyColouring();
    return 0;
}
