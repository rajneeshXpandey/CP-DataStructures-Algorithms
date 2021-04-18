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

int *visi;
vector<int> *adj;
int *dis;


void dfs(int node,int d){
     visi[node] = 1;
     dis[node] = d;
     for(auto nb : adj[node])
      {
          if(!visi[nb])
            dfs(nb,d+1);
      }

}


signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;
        cin>>n;
        adj = new vector<int>[n+1];
        visi = new int[n+1];
        dis = new int[n+1];
        memset(visi,0,sizeof(int)*(n+1));
        memset(dis,0,sizeof(int)*(n+1));
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        int mxnode=0;
        int dia=INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if(dia < dis[i])
             {
                 mxnode = i;
                 dia = dis[i];
             }
        }
        memset(visi, 0, sizeof(int) * (n + 1));
        memset(dis, 0, sizeof(int) * (n + 1));
        dfs(mxnode,0);
        dia = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (dia < dis[i])
            {
                mxnode = i;
                dia = dis[i];
            }
        }

        cout<<3*dia<<endl;
        
        
    }
    return 0;
}