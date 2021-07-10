#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)

using namespace std;
using ll = long long;

struct Edge { 
	int src, dest, weight; 
}; 

struct Graph { 

	int V, E; 

	struct Edge* edge;
    struct Edge *edge1;
}; 

struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[E];

    return graph; 
} 

int BellmanFord(struct Graph* graph, int src,int index) 
{ 
	int V = graph->V; 
	int E = graph->E; 
	int dist[V]; 

	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX; 
	dist[src] = 0; 

	for (int i = 1; i <= V - 1; i++) { 
		for (int j = 0; j < E; j++) { 
			int u = graph->edge[j].src; 
			int v = graph->edge[j].dest; 
            
			int weight = graph->edge[j].weight; 
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
		} 
	} 

	for (int i = 0; i < E; i++) { 
		int u = graph->edge[i].src;
        int v = graph->edge[i].dest; 
		int weight = graph->edge[i].weight; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 		 
			return 0; 
		} 
	} 

	return dist[index]; 
} 

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
    
        int V;
        cin >> V;

        vector<int> a(V);
        rep(i, V) cin >> a[i];

        int E = V-1;
        struct Graph *graph = createGraph(V, E);
        for (size_t i = 0; i < E; i++)
        {
            int src,dest;
            cin>>src>>dest;
            graph->edge[i].src = src-1;
            graph->edge[i].dest = dest - 1;
            graph->edge[i].weight = 1;

            
        }
     vector<int> result;
      for (size_t i = 0; i < V; i++)
      { int min_sum = 0;
          for (size_t j = 0; j < V; j++)
          {
              if(i != j){
                  int short_path = BellmanFord(graph, i, j);
                  min_sum += short_path*a[j];
              }
          }
           result.push_back(min_sum);
           }

       for (size_t i = 0; i < V; i++)
       {
         cout<<result[i]<<" ";
       }
           
        cout<<endl;
  }
	return 0; 
} 
