#pragma once
#include <queue>

#include "Graph.h"

class BFS
{
private:
    Graph* graph_;
    PriorityQueue<Location>* queue_;
public:
    BFS(Graph* graph)
    {
        this->graph_ = graph;
        queue_ = new PriorityQueue<Location>(graph->GetNumberVertices());
    }
    PriorityQueue<Location>* GetAllAdjacentUnVisited(Location* current)
    {
        PriorityQueue<Location>*unVisited = new PriorityQueue<Location>(graph_->GetNumberVertices());
        PriorityQueue<Location>*adjacentVerticies = graph_->GetAdjacentVertices(*current);//<-----
        while (!adjacentVerticies->IsEmpty())
        {
            Location* adj = adjacentVerticies->Remove();
            if (!adj->wasVisited)
            {
                unVisited->Insert(adj);
            }
        }
        return unVisited;
    }
    void Traverse(Location* start)
    {
        start->wasVisited = true;
        queue_->Insert(start);
        start->DisplayL();
        while (queue_->IsEmpty() == false)
        {
            Location* current = queue_->Remove();
            PriorityQueue<Location> * adjQueue = GetAllAdjacentUnVisited(current);
            while (adjQueue->IsEmpty() == false)
            {
                Location* adj = adjQueue->Remove();
                adj->wasVisited = true;
                adj->DisplayL();
                queue_->Insert(adj);
            }
        }
    }
};
