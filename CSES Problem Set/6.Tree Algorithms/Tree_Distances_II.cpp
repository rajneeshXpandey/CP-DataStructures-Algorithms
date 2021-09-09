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

pair<int, int> dfs(vector<vector<int>> &adj, vector<int> &visi, vector<int> &subtree, int root, int &sum)
{
    int sz = 0;
    int subsum = sum;
    sum++;
    visi[root] = 1;
    for (auto child : adj[root])
    {
        if (!visi[child])
        {
            auto vals = dfs(adj, visi, subtree, child, sum);
            sz += vals.first;
            subsum += vals.second;
        }
    }
    sum--;
    subtree[root] = 1 + sz;
    return {subtree[root], subsum};
}
void SumDist(vector<vector<int>> &adj, vector<int> &visi, vector<int> &subtree, vector<int> &ans, int n, int root, int par)
{
    /* By every change in reference of nodes shifting happens*/
    if (root != 0)
        ans[root] = ans[par] - subtree[root] + n - subtree[root];
    visi[root] = 1;
    for (auto child : adj[root])
    {
        if (!visi[child])
        {
            SumDist(adj, visi, subtree, ans, n, child, root);
        }
    }
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
{

    vector<int> ans(n, 0), subtree(n, 0), visi(n, 0);
    vector<vector<int>> adj(n);

    for (auto edg : edges)
    {
        adj[edg[0]].push_back(edg[1]);
        adj[edg[1]].push_back(edg[0]);
    }

    int root = 0, sum = 0;
    auto rootans = dfs(adj, visi, subtree, root, sum);
    ans[root] = rootans.second;

    visi.clear();
    visi.resize(n, 0);
    SumDist(adj, visi, subtree, ans, n, 0, -1);

    return ans;
}

void solve()
{  
    int n,u,v;
    cin>>n;
    vector<vector<int>> edges;
    forn(i,n-1){
        cin>>u>>v;
        u--,v--;
        edges.pb({u,v});
    }
    vector<int> ans = sumOfDistancesInTree(n,edges);

    for(auto dis : ans){
        cout<<dis<<' '; 
    }
    cout<<endl;
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