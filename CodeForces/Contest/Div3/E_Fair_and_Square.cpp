#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define generate_random(vect) generate(all(vect), rand); // fill vect with ramdom nums
#define binary_rep(n) bitset<32>(n);                     // binary representation of a number
#define setbits(x) __builtin_popcountll(x)               // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)                 // zeros before first setbit
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// useful functions
inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); } // gcd
// power in mod
inline ll power(ll a, ll n, ll mod)
{
    a %= mod;
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
inline ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

// Debugging
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
template <typename T>
inline void printDS(T dataStructure)
{
    for (auto val : dataStructure)
        cout << val << ' ';
    cout << endl;
}

// numeric values
// #define mod 1000000007   //1e9+7
// #define mod 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

bool perfectsqr(int x){
    int l=1,r=x;
    while(l<=r){
        int sqr = (l+r)/2;
        if(sqr*sqr==x) return true;
        if(sqr*sqr<x) l = sqr+1;
        else r = sqr-1;
    }
    return false;
}

int dfs(vector<vector<int>>& tree, int node, int par,vector<int>& arr,vector<int>& isperfect,vector<int>& subtreenodes, int& ans, int n){
    subtreenodes[node] = 1;
    vector<int> childs_nodes_branches;

    for(auto& child: tree[node]){
        if(child != par){
            int child_node_count = dfs(tree,child,node, arr, isperfect,subtreenodes,ans,n);
            subtreenodes[node] += child_node_count;
            childs_nodes_branches.pb(child_node_count);
        }
    }
    if(isperfect[node]){
        if(n-subtreenodes[node] > 0)
            childs_nodes_branches.pb(n-subtreenodes[node]);

        int running_sum = 0, running_pairs = 0;
        for(int i=0;i<childs_nodes_branches.size();i++){
            int s = childs_nodes_branches[i];
            ans += s*running_sum;    // take {node}: pair with an earlier branch
            ans += s*running_pairs;  // skip {node}: pair with two earlier branches
            running_pairs += s*running_sum;
            running_sum   += s;
        }
    }
    return subtreenodes[node];
}

void solve()
{
    int n,u,v;
    cin >> n;
    vector<int> arr(n),isperfect(n,0), subtreenodes(n,0);
    forn(i,n){
         cin>>arr[i];
         if(perfectsqr(arr[i])) isperfect[i] = 1;
    }
    vector<vector<int>> tree(n);
    forn(i, n-1){ 
        cin >> u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    int ans=0;
    dfs(tree,0,-1, arr, isperfect,subtreenodes,ans,n);
    cout<<ans<<endl;
}

signed main()
{
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}