#ifndef GRAPHAL_H
#define GRAPHAL_H

#include<bits/stdc++.h>

struct Edge;

struct Vertex
{
    int element;
    Vertex *VNext;
    Edge *EdgeList;
    bool visited;
};

struct Edge
{
    Vertex *AdjV;
    Edge *ENext;
};
#endif