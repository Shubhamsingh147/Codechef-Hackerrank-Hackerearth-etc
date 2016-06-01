#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
int V;
int graph[10001][10001];
int max(int a, int b)
{
  return a>b?a:b;
}
int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
int printSolution(int dist[], int n, int dest)
{
    if(dist[dest]!=INT_MAX)
        cout<<dist[dest]<<endl;
      else
        cout<<"-1"<<endl; 
}
void dijkstra(int src, int dest)
{
     int dist[V];
 
     bool sptSet[V]; 
 
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     dist[src] = 0;
 
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
 
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
     printSolution(dist, V, dest);
}

int main(){

  int m,x,y,z,s,d;
  cin>>m;
  V = INT_MIN;
  for (int i = 0; i < m; ++i)
  {
    cin>>x>>y>>z;
    V = max(V,max(x,y));
    if(graph[x-1][y-1]!=0)
      graph[x-1][y-1] = min(z,graph[x-1][y-1]);
    else
      graph[x-1][y-1] = z;
    graph[y-1][x-1] = graph[x-1][y-1];
  }
  cin>>s>>d;
  dijkstra(s-1,d-1);
}