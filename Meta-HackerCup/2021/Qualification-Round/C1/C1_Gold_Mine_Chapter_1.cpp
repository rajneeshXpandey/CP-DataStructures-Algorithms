#include "bits/stdc++.h"
using namespace std;

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
#define removeDuplicate(x) \
    sort(all(x));          \
    x.erase(unique(all(x)), x.end())       //remove Duplicate
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007                                        //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI 3.141592653589793238
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

// *********************** Code Begins ************************ //
void dfs(vector<vector<int>> &adj,vector<int> &visi,vector<int> &c,int root,int &ans,int &sum){
    bool isLeaf = true;
    visi[root] = 1;
    sum += c[root];
    for(auto nb : adj[root])
     {
         if(!visi[nb])
          { 
              isLeaf = false;
              dfs(adj,visi,c,nb,ans,sum);
          }
     }
     if(isLeaf)
       {  
           ans = max(ans,sum);
       }
    sum -= c[root];
}
void solve()
{
    int n,u,v;
    cin >> n;
    vector<int> c(n);
    forn(i, n) cin >> c[i];
    vector<vector<int>> adj(n);
    forn(i,n-1){
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int gold = c[0];
    multiset<int> st;
    //algorithm
    for(auto tuns : adj[0]){
        vector<int> visi(n,0);
        visi[0] = 1;
        int collectedGold = -inf,sum = 0;
        dfs(adj, visi,c, tuns,collectedGold,sum);
        st.insert(collectedGold);
    }
    if(st.size()==1)
      gold += *st.begin();
    else if (st.size()>1)
    {
         auto it = st.end();
         it--;
         gold += *it;
         it--;
         gold += *it;
    }
    cout<<gold<<endl;
}

signed main()
{
    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout<<"Case #"<< i <<": ";
        solve();
    }
}