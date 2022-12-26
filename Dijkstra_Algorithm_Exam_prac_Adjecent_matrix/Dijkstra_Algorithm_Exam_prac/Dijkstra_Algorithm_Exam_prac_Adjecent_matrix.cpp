#include <iostream>
using namespace std;

#define INF 999

int V ,src, cost[100][100];
int dist[100];
bool visited[100] = {0};
int parent[100];

void init()
{
    for (int i = 0; i < V; ++i)
    {
        parent[i] = i;
        dist[i] = INF;
    }
    dist[src] = 0;
}

int getNearest()
{
    int minvalue = INF;
    int minnode = 0;
    for (int i = 0; i < V; ++i)
    {
        if ( !visited[i] && dist[i] < minvalue)
        {
            minvalue = dist[i];
            minnode = i ;
        }
    }
    return minnode;
}

void dijkstra()
{
    for (int i = 0; i < V; ++i)
    {
        int nearest = getNearest();
        visited[nearest] = true;

        for (int adj = 0; adj < V; ++adj)
        {
            if (cost[nearest][adj] != INF &&
                dist[adj] >dist[nearest]+cost[nearest][adj] )
            {
                dist[adj] =dist[nearest]+cost[nearest][adj];
                parent[adj] = nearest;
            }
                
        }
    }
}


void display()
{
    cout << "Node:\t\t\tCost :\t\t\tPath" << endl;
    
    for (int i = 0; i < V; ++i)
    {
        cout << i << " \t\t\t" << dist[i] <<"\t\t\t"<< " ";
        cout << i << " ";

        int parnode = parent[i];

        while (parnode != src)
        {
            cout << " <-" << parnode << " ";
            parnode = parent[parnode];
        }
        cout << endl;
        
    }
}
int main(int argc, char* argv[])
{
   cout << " Number of vertices :";
    cin>>V;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> cost[i][j];
        }
    }
    cout << "src node :";
    cin >> src;
    init();
    dijkstra();
    display();
    
}


//this needs to be copied inn after choosing 9 verticies!!!!
/*
0   3   999 999 999 999 999 12 999
3   0   6   999 999 999 999 5   999
999  6   0   4  999   8 999 999 3
999 999 4  0   7   6  999 999 999
999 999  999 7   0   5  999 999 999
999 999 8  6  5  0  6   999 999
999 999 999 999 999 6   0   3   4
12 5   999 999 999 999 3   0   6
999 999 3  999 999 999 4   6   0



*/

