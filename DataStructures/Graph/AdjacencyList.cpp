#include<bits/stdc++.h>
using namespace std;


// The Graph structure is as folows

// Function to print graph
// adj: array of vectors to represent graph
// V: number of vertices
void printGraph(vector<int> adj[], int V)
{
    // Your code here
    for(int i=0;i<V;i++){
       cout<<i; 
        for(auto it: adj[i])
          cout<<"-> "<<it;
          
          cout<<endl;
          
    }

}
// Input:       Output:
// 1            // 0-> 1-> 4
// 5 7          // 1-> 0-> 2-> 3-> 4
// 0 1          // 2-> 1-> 3
// 0 4          // 3-> 1-> 2-> 4
// 1 2          // 4-> 0-> 1-> 3
// 1 3
// 1 4
// 2 3
// 3 4


int main()
{  
   int t;
   cin>>t;
   while(t--)
    {  int v, e;
       cin>>v>>e;
       int a, b;
       vector<int> adj[v];
       for(int i=0;i<e;i++)
       {
 		    cin>>a>>b;
 		    adj[a].push_back(b);
 		    adj[b].push_back(a);
       }
		printGraph(adj, v);
       
     }
    return 0;
}

