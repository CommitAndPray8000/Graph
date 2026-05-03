#include<bits/stdc++.h>
using namespace std;


//|||||||||||||||||||||||  For Directed  and In-Directed Graph |||||||||||||||||
//|||||||||||||||||||||||  Done with 2D array or Adjacency Matrix |||||||||||||||
class Graph
{
    vector<vector<int>> Graph_arr;
    bool DirectedOrNot;
    Graph(int GraphType)
    {
        if(GraphType == 1)
            DirectedOrNot = false;

        else
            DirectedOrNot = true;
    }


    void Insert_Vertex()
    {

        for(int i=0;i<size(Graph_arr);i--)
        {
            Graph_arr[i].push_back(0);
        }
        Graph_arr.push_back(vector<int>(size(Graph_arr), 0));

        
    }

    void AddPath(int a, int b)
    {
        Graph_arr[a-1][b-1] = 1;

        if(!DirectedOrNot)
            Graph_arr[b-1][a-1] = 1;

    }

    bool PathExists(int a, int b)
    {
        if(Graph_arr[a-1][b-1] == 1)
            return true;

        return false;
    }


    


};