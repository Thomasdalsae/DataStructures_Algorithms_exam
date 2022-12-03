#pragma once
#include <iomanip>

#include "Location.h"
#include "PriorityQueue.h"

class Graph
{
public:
    Location** vertices;
private:
    int** adjMat;
    static const int INF = 99999999;
    int numberVertices;
    int size;

public:
    Graph(int size)
    {
        this->size = size;
        numberVertices = 0;

        vertices = new Location*[size];

        adjMat = new int*[size];
        //this will create a new one-dimensional array for every one-dimensional array elements
        //creating a two-dimensional array;
        for (int i = 0; i < size; ++i)
        {
            adjMat[i] = new int[size];
        }

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                adjMat[i][j] = INF;
            }
    }

    void AddEdge(int start, int end, int weight)
    {
        adjMat[start][end] = weight;
    }

    void AddVertex(Location* vertex)
    {
        vertices[numberVertices] = vertex;
        numberVertices++;
    }

    void Display()
    {
        
        for (int j = 0; j < size; ++j)
        {
            cout << "\t" << setw(5) << "[ " << vertices[j]->name << "  ]";
        }
        cout << endl;
        for (int i = 0; i < size; ++i)
        {
            cout  << vertices[i]->name << "\t ";

            for (int j = 0; j < size; ++j)
            {
                cout <<setw(9)<< adjMat[i][j] << "\t" ;
            }
            cout << endl;
        }
    }

    PriorityQueue<Location>* GetAdjacentVertices(Location vertex)
    {
        PriorityQueue<Location>* adjacent = new PriorityQueue<Location>(numberVertices);
        for (int i = 0; i < numberVertices; ++i)
            if (adjMat[vertex.key][i] != INF)
            {
                adjacent->Insert(vertices[i]);
            }
        return adjacent;
    }

    int GetNumberVertices()
    {
        return numberVertices;
    }
};
