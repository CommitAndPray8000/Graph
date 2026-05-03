#include<bits/stdc++.h>
#include"/media/muhammadyahya/Local Disk/Documents/KU/DSA/Queue/DynamicQueue.cpp"
#include"/media/muhammadyahya/Local Disk/Documents/KU/DSA/Stack/DynamicStack.cpp"
#include"GraphAL.h"
using namespace std;

class GraphAL
{

    Vertex *First= nullptr;

    bool DirecetedOrNot = false;

    public:

    GraphAL(int Direction)
    {
        if(Direction == 1)
        {
            DirecetedOrNot = true;
        }
        else
            DirecetedOrNot = false;
    }
    
    void Insert_Vertex(int value)
    {
        
        Vertex * temp = new Vertex;
        temp -> element = value;
        temp -> EdgeList = nullptr;
        temp -> VNext = nullptr;
        temp -> visited = false;

        if(First == nullptr)
        {
            First = temp;
            return;
        }
        Vertex * curr = First;

        while(curr -> VNext != nullptr)
            curr = curr -> VNext;

        curr -> VNext = temp;
    }

    Vertex *GetVerAddress(int v)
    {
        Vertex *curr = First;
        while(curr != nullptr)
        {
            if(curr -> element == v)
            {
                return curr;
            }
            curr = curr -> VNext;
        }
        return nullptr;
    }

    void AddEdge(int v1, int v2)
    {
        Edge * tempEdge = new Edge;
        tempEdge -> ENext = nullptr;
    
        Vertex * curr1 = GetVerAddress(v1);
        Vertex * curr2 = GetVerAddress(v2);

        if(curr1 == nullptr || curr2 == nullptr)
        {
            cout<<"One of the vertex does not exist.\n";
            return;
        }

        tempEdge -> AdjV = curr2;


        if(curr1 -> EdgeList == nullptr)
        {
            curr1 -> EdgeList =tempEdge;
            cout<<"Path between "<<v1<<" and "<<v2<<" Successfully added.\n";
        }
        else
        {
            Edge * currEdge = curr1 -> EdgeList;
            while(currEdge -> ENext != nullptr)
            {
                currEdge = currEdge -> ENext;
            }
            currEdge -> ENext = tempEdge;
            cout<<"Path between "<<v1<<" and "<<v2<<" Successfully added.\n";
        }
        

        if(!DirecetedOrNot)
        {
            tempEdge -> AdjV = curr1;
            if(curr2 -> EdgeList == nullptr)
            {
                curr2 -> EdgeList = tempEdge;
                cout<<"Path between "<<v2<<" and "<<v1<<" Also Successfully added.\n";
                return;
            }
            Edge * currEdge = curr2 -> EdgeList;
            while(currEdge != nullptr)
            {
                currEdge = currEdge -> ENext;
            }
            currEdge = tempEdge;
            cout<<"Path between "<<v2<<" and "<<v1<<" Also Successfully added.\n";
        }

    }


    void FindDegree(int v)
    {
        Vertex *curr1 = GetVerAddress(v);
        
        int Indegree = 0;
        int Outdegree = 0;
        
        Edge *temp = curr1 -> EdgeList;

        if(temp == nullptr)
        {
            Outdegree =0;
        }
        else
        {
            while(temp != nullptr)
            {
                Outdegree ++;
                temp = temp -> ENext;
            }
        }

        if(DirecetedOrNot)
        {
            Vertex *curr2 = First;
            while(curr2 != nullptr)
            {
                if(curr2 != curr1)
                {
                    temp = curr2 ->EdgeList;

                    while(temp != nullptr)
                    {
                        if(temp -> AdjV == curr1)
                        {
                            Indegree++;
                            break;
                        }
                        temp = temp -> ENext;
                    }
                }
                curr2 = curr2 -> VNext;
            }
            
        }

        if(DirecetedOrNot)
        {
            cout<<"The Indegree of vertex "<<v<<" is : "<<Indegree<<endl;
            cout<<"And The Outdegree of vertex "<<v<<" is : "<<Outdegree<<endl;
        }
        else
        {
            cout<<"The Degree of vertex "<<v<<" is : "<<Outdegree<<endl;
        }
    }

    Vertex* SearchByBFS(int v1, int v2)
    {
        Dynamic_Queue BFSQueue;
        Vertex *Start = GetVerAddress(v1);
        BFSQueue.EnQueue(Start);
        Start -> visited = true;
        Vertex *curr = nullptr;
        Vertex *result = nullptr;

        while(BFSQueue.first != nullptr)
        {
            curr = BFSQueue.DeQueue();
            if(curr -> element == v2)
            {
                result = curr;
                break;
            }
            Edge *tempEdge = curr-> EdgeList;
            while(tempEdge != nullptr)
            {
                if(!(tempEdge ->AdjV -> visited))
                {
                    BFSQueue.EnQueue(tempEdge -> AdjV);
                    tempEdge -> AdjV -> visited =true;
                }
                
                tempEdge = tempEdge -> ENext;
            } 
        } 

        curr = First;
        while(curr != nullptr)
        {
            curr -> visited = false;
            curr = curr -> VNext;
        }
        return result;
    }

    Vertex* SearchByDFS(int v1, int v2)
    {
        DynamicStack DFSStack;
        Vertex *Start = GetVerAddress(v1);
        Vertex *curr = nullptr;
        Vertex *result = nullptr;
        DFSStack.PushStack(Start);
        Start ->visited = true;
        while(DFSStack.top != nullptr)
        {
            bool backtrack = false;
            curr = DFSStack.top -> element;
            if(curr -> element == v2)
            {
                result = curr;
                break;
            }
            Edge *tempEdge = curr -> EdgeList;

            while(tempEdge!= nullptr)
            {
                
                if(!(tempEdge -> AdjV -> visited))
                {
                    DFSStack.PushStack(tempEdge -> AdjV);
                    tempEdge -> AdjV -> visited = true;
                    backtrack = true;
                    
                    break;
                }
                tempEdge = tempEdge -> ENext;
            }
            if(backtrack)
                continue;

            DFSStack.PopStack();
        }

        curr = First;
        while(curr != nullptr)
        {
            curr -> visited = false;
            curr = curr -> VNext;
        }
        return result;
    }

    void FindPath(int v1, int v2)
    {

        //|||||||| This is for finding path in general not the shortest path, copying the DFS above hope it works |||||||||||||||||||
        DynamicStack PathDFSStack;
        Vertex *Start = GetVerAddress(v1);
        Vertex *curr = nullptr;
        vector<int> result;
        bool pathfound = false;
        PathDFSStack.PushStack(Start);
        Start ->visited = true;
        while(PathDFSStack.top != nullptr)
        {
            bool backtrack = false;
            curr = PathDFSStack.top -> element;
            if(curr -> element == v2)
            {
                pathfound = true;
            }
            Edge *tempEdge = curr -> EdgeList;

            while(tempEdge!= nullptr && (!(pathfound)) )
            {
                
                if(!(tempEdge -> AdjV -> visited))
                {
                    PathDFSStack.PushStack(tempEdge -> AdjV);
                    tempEdge -> AdjV -> visited = true;
                    backtrack = true;
                    
                    break;
                }
                tempEdge = tempEdge -> ENext;
            }
            if(backtrack)
                continue;

            result.push_back(PathDFSStack.PopStack() -> element);
        }
        if(pathfound)
        {   
            cout<<"The path between "<<v1 <<" and "<<v2 <<" is: ";
            for(int i=size(result)-1; i>=0; i--)
            {
                cout<<result[i]<<" --> ";
            }
            cout<<endl;
        
        }
        else
        {
            cout<<"The path between "<<v1 <<" and "<<v2 <<" could not be found.\n ";
        }
        curr = First;
        while(curr != nullptr)
        {
            curr -> visited = false;
            curr = curr -> VNext;
        }
    }

    bool IsCyclic()
    {
         
    }

    void DisplayAdjList()
    {
        Vertex *curr = First;
        while(curr != nullptr)
        {
            cout<<curr -> element;
            Edge *temp = curr -> EdgeList;
            while(temp != nullptr)
            {
                cout<<"--> "<<temp -> AdjV -> element;
                temp = temp -> ENext;
            }
            curr = curr -> VNext;
            cout<<"\n";
        }
    }

    
};