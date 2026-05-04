#include<bits/stdc++.h>
#include"GraphAL.cpp"
using namespace std;

int main()
{
    //||||||||||   Graph by Adjacency List  |||||||||||||||

    cout<<"Welcome to program of Graph by Adjacency List.\n";
    bool flag = false;
    int action;
    int direction;

    cout<<"Enter the number corrosponding to the action you want to perform.\n";
    cout<<"Enter 0 for undirected Graph and 1 for directed : ";
    cin>>direction;
    GraphAL myGraph = GraphAL(direction);
    while(!flag)
    {
        cout<<"1 for Inserting a Vertex, 2 for Adding an Edge,\n 3 for getting degree of a vertex, 4 for Displaying the Adjacency List,\n 5 for Searcing by BFS and 6 for Searching by DFS, \n 7 for Finding path, 8 for Checking if graph is Connected and \n 9 for checking if graph is Cyclic : ";
        cin>>action;

        switch(action)
        {
            case 1:
                int VNum;
                cout<<"Enter a number corrosponding to your vertex : ";
                cin>>VNum;
                cout<<"\n";
                myGraph.Insert_Vertex(VNum);
            break;

            case 2:
                int v1,v2;
                cout<<"Enter the starting vertex : ";
                cin>>v1;
                cout<<" Now the destination vertex : ";
                cin>>v2;
                cout<<"\n";
                myGraph.AddEdge(v1,v2);
            break;

            case 3:
                int v;
                cout<<"Enter the vertex you want to find Degree of : ";
                cin>>v;
                myGraph.FindDegree(v);

            break;

            case 4:
                myGraph.DisplayAdjList();
            break;

            case 5:
                cout<<"Enter the starting vertex : ";
                cin>>v1;
                cout<<" Now the destination vertex : ";
                cin>>v2;
                cout<<"\n";
                if(myGraph.SearchByBFS(v1,v2) == nullptr)
                {
                    cout<<"It is possibe to go from "<<v1<<" to "<<v2<<"\n";
                }
             else
                cout<<"It is not possibe to go from "<<v1<<" to "<<v2<<"\n";

            break;

            case 6:
                cout<<"Enter the starting vertex : ";
                cin>>v1;
                cout<<" Now the destination vertex : ";
                cin>>v2;
                cout<<"\n";
                if(myGraph.SearchByDFS(v1,v2) == nullptr)
                {
                    cout<<"It is possibe to go from "<<v1<<" to "<<v2<<"\n";
                }
             else
                 cout<<"It is not possibe to go from "<<v1<<" to "<<v2<<"\n";
            break;

            case 7:
                cout<<"Enter the starting vertex : ";
                cin>>v1;
                cout<<" Now the destination vertex : ";
                cin>>v2;
                cout<<"\n";
                myGraph.FindPath(v1,v2);
            break;

            case 8:
            {
                if(myGraph.IsConnected())
                {
                    cout<<"All vertices of the graph are connected\n";
                }
                else
                    cout<<"All vertices are not connected in this graph\n";
            }
            case 9:
            {
                if(myGraph.IsCyclic())
                {
                    cout<<"The graph has cycles present in it\n";
                }
                else
                    cout<<"There are no cycles in this graph\n";
            }

            default:
                cout<<"Program Successfully Exited.\n";
                return 0;
            break;

        }
    }
}
