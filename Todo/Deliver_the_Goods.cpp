#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b)  for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n-1)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define size(dataStructure) (ll)(dataStructure.size())
#define pb push_back
#define pii pair<int, int>
#define make_unique(vect) sort(all(vect)); vect.resize(unique(all(vect)) - vect.begin()); //remove Duplicate
#define generate_random(vect) generate(all(vect), rand); // fill vect with ramdom nums
#define rotate_by_k(vect,k) rotate(vect.begin(), vect.begin() + k, vect.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a)); // Create a set from a vector
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

typedef tuple<int, int, int> tuplei;

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// mt19937_64 rng(61378913);
/* usage - generate random numbers, just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline ll power(ll a, ll n){a %= mod; int res = 1; while(n){if (n & 1) res = (res * a) % mod; a = (a * a) % mod;n >>= 1;} return res;}
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
inline void assign1ton(vector<int> &v) { iota(v.begin(), v.end(), 1); }
template<typename T> inline void printDS(T dataStructure){for(auto val : dataStructure) cout<<val+1<<' '; cout<<endl;}
template<typename T> inline void print(T anything){cout<<anything<<"\n";}

// ********************************* Here we go!! ********************************** //

// Kosaraju's Algorithm for Strongly Connected Component

void dfs1(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order, int node)
{
    visited[node] = true;
    for (auto child : adj[node])
        if (!visited[child])
            dfs1(adj, visited, order, child);
    order.push_back(node);
}

void dfs2(vector<vector<int>> &adj_rev, vector<bool> &visited, vector<int> &component, int node)
{
    visited[node] = true;
    component.push_back(node);
    for (auto child : adj_rev[node])
        if (!visited[child])
            dfs2(adj_rev, visited, component, child);
}

void solve(){
    int n,m;
    // ... read n ...
    cin >> n >> m;
    vector<vector<int>> adj(n), adj_rev(n);
    vector<bool> visited,used;
    vector<int> order, component;
    int a, b;
    forn(i,m)
    {
        // ... read next directed edge (a,b) ...
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }
    visited.assign(n, false);
    vector<set<int>> adj_scc;
    vector<int> ans(n, -1);
    reverse(all(order));
    for (int i = 0; i < n; i++)
        if(!visited[i]){
            dfs1(adj,visited,order,i);
            //reverse(all(order));
            //printDS(order);
            ////return;
            //used.assign(n, true);
            //for(auto node : order)
            //    used[node] = false;
            //for(auto node : order)
            //{
            //    if(!used[node]){
            //        dfs2(adj_rev, used, component, node);
            //        printDS(component);
            //        //int res=size(adj_scc);
            //        //for(auto nodes : component){
            //        //    ans[nodes] = res-1;
            //        //}
            //        component.clear();
            //    }
            //}
            //order.clear();
            //adj.clear();
    }
    visited.assign(n, false);
    for (auto v : order)
        if (!visited[v])
        {
                dfs2(adj_rev, used, component, v);
                printDS(component);
                component.clear();
        }
    //printDS(ans);
}

signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    //cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}