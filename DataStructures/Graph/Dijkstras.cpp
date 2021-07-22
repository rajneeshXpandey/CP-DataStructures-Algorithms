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

vector<pii> *adj;
int *minDis;
int *path;
int *flag;

signed main()
{
    FIO;
    int v, e;
    cin>>v>>e;
    adj = new vector<pii>[v+1];
    minDis = new int[v+1];
    path = new int[v+1];
    flag = new int[v+1];

    for (int i = 0; i < e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i = 0; i <= v; i++)
    {
        minDis[i] = inf;
    }
    // source/starting vertex = 1
    minDis[1]=0;
    priority_queue<pii , vector<pii> , greater<pii> > minheap;
    // minheap = dis , node
    minheap.push({0,1});
    
    while (!minheap.empty())
    {
        int currNode = minheap.top().second;
        int currDis = minheap.top().first;

        minheap.pop();
        //this node is used for optimization
        flag[currNode] = true;

        // this will handle the case if already min dis is updated for currDis
        if (currDis > minDis[currNode])
            continue;

        for(auto edge : adj[currNode])
          {
    if (!flag[edge.first] and (currDis + edge.second < minDis[edge.first]))
              {
                  minDis[edge.first] = currDis + edge.second;
                  minheap.push({minDis[edge.first], edge.first});
                  path[edge.first] = currNode;
               }
          }
    }
    
    for (int i = 1; i <= v; i++)
    {
        cout<<minDis[i]<<" ";
    }
    return 0;
}