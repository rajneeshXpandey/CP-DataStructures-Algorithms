// rajneesh_1708 : Rajneesh Pandey
#include<bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx            priority_queue<int> // maxheap
#define pqmn   priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> *adj;
int *indeg;


vector<int> topoSort(int node)
{
    vector<int> v;
    // min heap
    priority_queue<int , vector<int> , greater<int>> q;

   for (int i = 1; i <=node; i++)
    {
        if(indeg[i]==0)
         q.push(i);
     }

     while(!q.empty())
    {
        int temp = q.top();
        q.pop();
        v.pb(temp);
        // cout<<temp<<" ";
        for (auto nb : adj[temp])
        {
           
            indeg[nb]--;
            if (indeg[nb] == 0)
                q.push(nb);
        }
     }

     return v;
}

signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
      int v,e;
      cin>>v>>e;
      adj = new vector<int>[v+1];
      indeg = new int[v+1];
      memset(indeg,0,sizeof(int)*(v+1));
      for (int i = 0; i < e; i++)
      {
          int u,v;
          cin>>u>>v;
          adj[u].pb(v);
          indeg[v]++;
      }
      vector<int> topo = topoSort(v);
    //   cout<<topo.size()<<" ";
      if(topo.size()==v)
       {
           for(auto x : topo)
            cout<<x<<" ";
       }
      else{
          cout << "Sandro fails."<<endl;
      } 
        
    }
    return 0;
}