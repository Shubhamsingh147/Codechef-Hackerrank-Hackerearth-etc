#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n,V,x,y;
  cin>>n>>V;
  int graph[V][V];
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      graph[i][j] = 0;
    }
  }
  for(int i=0;i<V;i++)
  {
      cin>>x>>y;
      graph[x][y]=1;
      graph[y][x]=1;
  }
  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
      }
    }
  }
    