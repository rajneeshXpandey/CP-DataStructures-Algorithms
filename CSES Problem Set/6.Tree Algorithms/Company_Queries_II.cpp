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

void dfs(int v, int p, vector<vector<int>> &adj, vector<vector<int>> &up, vector<int> &lev)
{
    up[v][0] = p;
    if (p >= 0)
        lev[v] = lev[p] + 1;
    for (int i = 1; i <= 19; ++i)
        up[v][i] = (up[v][i - 1] >= 0) ? up[up[v][i - 1]][i - 1] : -1;
    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v, adj, up, lev);
    }
}
int lift_node(int node, int jump_required, vector<vector<int>> &up)
{
    for (int i = 19; i >= 0; i--)
    {
        if (node <= -1 || jump_required <= 0)
        {
            break;
        }
        if (jump_required >= (1 << i))
        {
            jump_required = jump_required - (1 << i);
            node = up[node][i];
        }
    }
    return node;
}
int lca(int u, int v, vector<vector<int>> &up, vector<int> &lev)
{
    if (lev[u] < lev[v])
        swap(u, v);

    u = lift_node(u, lev[u] - lev[v], up);
    if (u == v)
        return u;

    for (int i = 19; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return lift_node(u, 1, up);
}

void solve()
{
    int n, q, v, u;
    cin >> n >> q;
    vector<vector<int>> adj(n), up(n, vector<int>(20, -1));
    vector<int> lev(n, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> v;
        v--;
        adj[i].pb(v);
        adj[v].pb(i);
    }
    dfs(0, -1, adj, up, lev);
    forn(i, q)
    {
        cin >> u >> v;
        u--;
        v--;
        cout << lca(u, v, up, lev)+1 << endl;
    }
}

signed main()
{
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}