// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define removeDuplicate(x)   sort(all(x)); x.erase(unique(all(x)),x.end())   //remove Duplicate
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //

/* ----- Calculating endPoint of Diameter --------- */

vector<int> dist;
vector<int> visi;

void dfs(vector<int> adj[], int node)
{
    visi[node] = 1;
    for (auto nb : adj[node])
    {
        if (!visi[nb])
        {
            dist[nb] += dist[node] + 1;
            dfs(adj, nb);
        }
    }
}

pii diameter(vector<int> adj[],int n)
{
    dist.resize(n, 0);
    visi.resize(n, 0);
    dfs(adj, 0);
    int farNode1 = max_element(all(dist)) - dist.begin();
    dist.clear();
    visi.clear();
    dist.resize(n, 0);
    visi.resize(n, 0);
    dfs(adj, farNode1);
    int farNode2 = max_element(all(dist)) - dist.begin();
    int dia = *max_element(all(dist));
    return mp(farNode1, farNode2);
}

/* ------- bfs for dist from endpoint -------- */
void bfs(vector<int> adj[], int n,int root,vector<int> &dis){
    vector<int> vis(n,0);
    queue<int> q;
    q.push(root);
    int lev = 0;
    while(!q.empty()){
        int sz = q.size();
        forn(i,sz){
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto nb : adj[node])
                if(!vis[nb]){
                    q.push(nb);
                }

            dis[node] = lev;        
        }
        lev++;
    }
}

void solve()
{
    int n;
    int u, v;
    cin >> n;
    vector<int> adj[n];
    forn(i, n - 1)
    {
        cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    /* ------------ Method 1 : using diameter endPoint ----------  */
            /* 
                        n1     n2
                        |     |
            "ep1"-------n3----n4-----n5-----"ep2"
                        |            |
                        n6            n7       

                here maxDis_of_i = max(i_dis_from_ep1,i_dis_from_ep2) , 
                        to prof : if not then the node with max_dis_from_i should be endpoint
            */
        pii ep = diameter(adj,n);
        //deb2(ep.ff, ep.ss);
        vector<int> dist_ep1(n,0);
        vector<int> dist_ep2(n,0);
        bfs(adj,n,ep.ff,dist_ep1);
        bfs(adj,n,ep.ss,dist_ep2);
        vector<int> maxDisfromI(n);
        forn(i,n){
            maxDisfromI[i] = max(dist_ep1[i], dist_ep2[i]);
        }
        forn(i, n)
        cout<< maxDisfromI[i] <<' ';
        cout<<endl;   

    /* Method 2 : General approach : max(depth[i],par_answer_without_i) */
}

signed main()
{
    FastIO;
    int tt = 1;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}