#include "Graph.h"
#include "BFS.h"


int main(int argc, char* argv[])
{

    Graph* g = new Graph(9);
    Location* startVert = new Location(0,'A');
    
    g->AddVertex(startVert);
    g->AddVertex(new Location(1, 'B'));
    g->AddVertex(new Location(2, 'C'));
    g->AddVertex(new Location(3, 'D'));
    g->AddVertex(new Location(4, 'E'));
    g->AddVertex(new Location(5, 'F'));
    g->AddVertex(new Location(6, 'G'));
    g->AddVertex(new Location(7, 'H'));
    g->AddVertex(new Location(8, 'I'));

    g->AddEdge(0,1,1); //A-B = 1;
    g->AddEdge(0,2,1); //A-C = 1;
    g->AddEdge(0,3,1); //A-D = 1;
    g->AddEdge(0,4,1); //A-E = 1;
    
    g->AddEdge(1,5,1); //B-F = 1;
    g->AddEdge(5,7,1); //F-H = 1;
    
    g->AddEdge(3,6,1); //D-G = 1;
    g->AddEdge(6,8,1); //G-I = 1;

    g->Display();

    cout <<setw(9)<< "---------------------------------------------------------------------------------------------------------------" << endl;
    
    BFS* b = new BFS(g);
    b->Traverse(startVert);

    
    return 0;
}
